#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
//***********************************************************************************
//***********************************************************************************
//pines
//-----------------------------------------------------------------
// lector de bateria
#define at 0// pin analogico de tension
#define tp4056 12//Entrada del modo tp4056
#define boc 11 //bateria o cargador
#define mh 10// entrada para forzar modo ahorro
#define cc 9//cierre de carga
#define boton_p 8//para dar el porcentaje
//-----------------------------------------------------------------
// Sensor_color
#define led 4
#define boton_c 5
#define buzzer 6
//-----------------------------------------------------------------
//-----------------------------------------------------------------
// Sensor distancia
#define TRIG 8
#define ECO  7
#define boton_d  6
//-----------------------------------------------------------------
//***********************************************************************************
//***********************************************************************************
//  Variables
//-----------------------------------------------------------------
// lector de bateria
int porcentaje;
bool md_ahorro;
bool cod;
//-----------------------------------------------------------------
// Sensor_color
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximidad = 0;
//-----------------------------------------------------------------
// Sensor distancia
int distancia;
//-----------------------------------------------------------------

//***********************************************************************************
void setup() 
{
  Serial.begin(9600);
//-----------------------------------------------------------------
//iniciacion para el lector de bateria y carga
//-----------------------------------------------------------------
//pin mode
  pinMode(cc, OUTPUT);
  pinMode(boc, OUTPUT);
//salida iniciada
  digitalWrite(cc, HIGH);//lo activa para que siempre este activado, solo se cierra cuando haga una lectura
//-----------------------------------------------------------------
//iniciacion de la libreria para el GY9960
//-----------------------------------------------------------------
//color
  apds.init();
  apds.enableLightSensor(false);
//proximidad
  apds.enableProximitySensor(false);
  apds.setProximityGain(PGAIN_4X);
//-----------------------------------------------------------------
//iniciacion para sensor de distancia
//-----------------------------------------------------------------
  pinMode(TRIG, OUTPUT);
//-----------------------------------------------------------------
}
//***********************************************************************************
void loop() 
{
  carga_o_descarga();
  porcentaje_bateria();
  modo_ahorro();

  if(digitalRead(boton_d))
  {
    distancia = d_ultra();
    Serial.print("distancia: ");
    Serial.println(distancia);
  }

  if(digitalRead(boton_c))
  {
      que_color();    
      Serial.println("*************************************");
  }
  
  if(digitalRead(boton_p))
  {
    Serial.print("porcentaje de bateria es: ");
    Serial.print(porcentaje);
    Serial.println("%");   
  }
  
  delay(1000);
}
//***********************************************************************************
//Funciones
//***********************************************************************************
int porcentaje_bateria()// funcion para sacar el porcentaje de bateria
{
// si esta en modo carga cierra por un instante el proceso de carga para que este no afecte la lectura
//------------------------------
  if(digitalRead(tp4056))
  {
    digitalWrite(cc, LOW);
    delay(10);
  }
//------------------------------
//saca el porcentaje de bateria 
//--------------------------------------------------------------------------------
  porcentaje = map(map(analogRead(at), 0, 1023, 0, 500), 320, 420, 0, 100);// el primer map saca la tension y segundo el porcentaje
//  los valores de 320 a 420 serian de 3.2 a 4.2 v, esto baria en funcion de la ocilacion de nuestra bateria, este es el normal
//--------------------------------------------------------------------------------
  digitalWrite(cc, HIGH);//vuelve a activar el sistema de carga
  return porcentaje;
}
//***********************************************************************************
void modo_ahorro()//algoritmo de modo ahorro
{
   bool tm = md_ahorro;
// verifica que no este cargando la bateria, si esta cargando desactiva modo ahorro
//--------------------------------
  if(cod)
    md_ahorro = 0;
//--------------------------------
//  consulta si el modo ahorro esta activado
//--------------------------------
  else if(digitalRead(mh))
    md_ahorro = 1;
//--------------------------------
// si el porcentaje es menor a 15 pone en modo ahorro
//--------------------------------
  else if(porcentaje<15)
    md_ahorro = 1;
  else
    md_ahorro = 0;
//--------------------------------
//  si cambia el modo ahorro envia un mensaje
//---------------------------------------------------------
  if(tm != md_ahorro)
    {
      if(md_ahorro)
        Serial.println("modo ahorro activado");
      else
        Serial.println("modo ahorro desactivado");
    }
//---------------------------------------------------------
}
//***********************************************************************************
void carga_o_descarga()
{
//  Usa el ultimo estado de la carga para ver si hubo un cambio y en funcion a eso avisar al usuario    
    if(cod != digitalRead(tp4056))
    {
        if(digitalRead(tp4056) == 1)
            Serial.println("se a conectado un cargador a la bateria");
        else
            Serial.println("se a desconectado el cargador de la bateria");
    }
//  Guarda variable del ultimo estado
    cod = digitalRead(tp4056);
//  Segun si esta en carga o descarga elige que fuente de alimetacion va a usar
    if(!cod)
        digitalWrite(boc, HIGH);
    else
        digitalWrite(boc, LOW);
}
//***********************************************************************************
void que_color()// en esta funcion se tiene que intentar determinar un color en concreto
{
//------------------------------------------------------------
  digitalWrite(led, HIGH);// prende un led blanco para mejorar la lectura
//------------------------------------------------------------
// variables declaradas 
//------------------------------------------------------------
  int cont = 0;
  uint16_t R;
  uint16_t G;
  uint16_t B;
  float Ambiental = crgbc(0);//  saca el valor ambiental
//------------------------------------------------------------
//se fija que este a una distancia optima  
//----------------------------------------------------------------------------------
  while(cont<2000)//espera 2s
  {
    apds.readProximity(proximidad);// lee la distancia del 9960
    if(proximidad>170&&proximidad<255)// si esta esta en estos parametros empieza a contar por 2s
    {
      cont++;// suma 1us al contador
      analogWrite(buzzer, 1);// avisa que esta en pocision correcta
    }
    else// si se sale del rango resetea el contador
    {
      cont = 0;// reset del contador de us
      analogWrite(buzzer, 2);// indica que no esta en posicioon
    }
    delay(1);
  }
  analogWrite(buzzer, 0);// si todo salio bien apaga el indicador
//  saca el valor ambiental
//----------------------------------------------------------------------------------  
//  convierte este valor de 0 a 255
  R = map((((crgbc(1)/Ambiental)*2.8)*100), 0, 100, 0, 255);
  G = map((((crgbc(2)/Ambiental)*2.8)*100), 0, 100, 0, 255);
  B = map((((crgbc(3)/Ambiental)*2.8)*100), 0, 100, 0, 255);
  digitalWrite(led, LOW);// apaga el led blanco que ya no es necesario
//----------------------------------------------------------------------------------
//  en este espacio con if segun un parametros se veria que colores van a ser  

//-----------------------------------------------------------------------------------
// escribe el color (en este caso como aun no hice el if pongo el rgb mejorado)
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
}
//***********************************************************************************
int crgbc(uint16_t num)// en esta funcion sacamos los valores del sensor
{
// toma un color segun el que se le pida
  switch (num)
  {
    case 0:// la luz ambiental
      apds.readAmbientLight(num);
      Serial.print("Ambiental: ");
      break;
    case 1://Rojo
      apds.readRedLight(num);
      Serial.print("Rojo: ");
      break;
    case 2: // Verde
      apds.readGreenLight(num);
      Serial.print("Verde: ");
      break;
    case 3: // Azul
      apds.readBlueLight(num);
      Serial.print("Azul: ");
      break;
  }
  Serial.println(num); // escribe el valor  
  return num; // retorna el valor
}
//***********************************************************************************
int d_ultra()
{
    int duracion;
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    duracion = pulseIn(ECO,HIGH);
    return (duracion / 58.2);
}
//***********************************************************************************