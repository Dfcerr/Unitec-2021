#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
//***********************************************************************************
//***********************************************************************************
//pines
//-----------------------------------------------------------------
// lector de bateria
#define at 0//ea/ pin analogico de tension
#define tp4056 12//e/ Entrada del modo tp4056
#define boc 11 //s/ bateria o cargador 
#define cc 10//s/ cierre de carga
#define mh 6//e/ entrada para forzar modo ahorro
#define boton_p 5//e/ para dar el porcentaje
//-----------------------------------------------------------------
// Sensor_color
#define led 13//s/
#define boton_c 4//e/
#define buzzer 9//sa/
//-----------------------------------------------------------------
//-----------------------------------------------------------------
// Sensor distancia
#define TRIG 8//s/
#define ECO 7//e/
#define boton_d 2//e/
//-----------------------------------------------------------------
//***********************************************************************************
//***********************************************************************************
//  Variables
//-----------------------------------------------------------------
// lector de bateria
bool md_ahorro = 0;
bool cod = 0;
//-----------------------------------------------------------------
// Sensor_color
SparkFun_APDS9960 apds = SparkFun_APDS9960();
//-----------------------------------------------------------------
// Sensor distancia
int distancia;
int dl = 0;
//-----------------------------------------------------------------

//***********************************************************************************
void setup() 
{
  Serial.begin(9600);
//-----------------------------------------------------------------
//iniciacion para el lector de bateria y carga
//-----------------------------------------------------------------
//pin mode
//-----------------------------------------------------------------
  pinMode(boton_p, INPUT_PULLUP);
  pinMode(cc, OUTPUT);
  pinMode(boc, OUTPUT);
//-----------------------------------------------------------------
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
  bateria(0);
  
  if(!digitalRead(boton_p))
  {
    Serial.print(bateria(1));
    Serial.println("%");
  }

  s_ultra();

  if(digitalRead(boton_c))
  {
      crgbc();    
      Serial.println("*************************************");
  }
  
  delay(300);dl+=300;
}
//***********************************************************************************
//Funciones
//***********************************************************************************
int bateria(bool m_boton)
{
  byte porcentaje;
  bool tm = md_ahorro;
//************************************************************************************************************
// verificacion del modo de alimentacion de la bateria
//--------------------------------
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
//************************************************************************************************************ 
// si esta en modo carga cierra por un instante el proceso de carga para que este no afecte la lectura
//------------------------------
  if(!cod || m_boton)// esto hace que si no esta cargando o el boton esta presionado tome el porcentaje
  {
    if(cod)//si esta cargando desactiva la carga de la bateria
    {
      digitalWrite(cc, LOW);
      delay(5);
    }
//------------------------------
//saca el porcentaje de bateria 
//--------------------------------------------------------------------------------
    porcentaje = map(map(analogRead(at), 0, 1023, 0, 500), 320, 420, 0, 100);// el primer map saca la tension y segundo el porcentaje
//  los valores de 320 a 420 serian de 3.2 a 4.2 v, esto baria en funcion de la ocilacion de nuestra bateria, este es el normal
  }
//--------------------------------------------------------------------------------
  digitalWrite(cc, HIGH);//vuelve a activar el sistema de carga
//************************************************************************************************************
// verificacion del modo
//--------------------------------
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
//************************************************************************************************************
  return porcentaje;//retorna porcentaje
}
//***********************************************************************************
void crgbc()// en esta funcion se tiene que intentar determinar un color en concreto
{
//------------------------------------------------------------
  digitalWrite(led, HIGH);// prende un led blanco para mejorar la lectura
//------------------------------------------------------------
// variables declaradas 
//------------------------------------------------------------
  int cont = 0;
  uint8_t proximidad;
  uint16_t R;
  uint16_t G;
  uint16_t B;
  float Ambiental;
//------------------------------------------------------------
//se fija que este a una distancia optima  
//----------------------------------------------------------------------------------
  while(cont<40)//espera 2s
  {
    apds.readProximity(proximidad);// lee la distancia del 9960
    if(proximidad>170&&proximidad<255)// si esta esta en estos parametros empieza a contar por 2s
    {
      cont++;// suma 1us al contador
      analogWrite(buzzer, 0);// avisa que esta en pocision correcta
    }
    else// si se sale del rango resetea el contador
    {
      cont = 0;// reset del contador de us
      analogWrite(buzzer, 1);// indica que no esta en posicioon
    }
    delay(50);
  }
  analogWrite(buzzer, 0);// si todo salio bien apaga el indicador
//------------------------------------------------------------
// saca los colores puros
//------------------------------------------------------------
  apds.readAmbientLight(Ambiental);;//  saca el valor ambiental
  apds.readRedLight(R); 
  apds.readGreenLight(G); 
  apds.readBlueLight(B); 
//------------------------------------------------------------
//  saca el valor ambiental
//----------------------------------------------------------------------------------  
//  convierte este valor de 0 a 255
  R = map((((R/Ambiental)*2.8)*100), 0, 100, 0, 255);
  G = map((((G/Ambiental)*2.8)*100), 0, 100, 0, 255);
  B = map((((B/Ambiental)*2.8)*100), 0, 100, 0, 255);
  digitalWrite(led, LOW);// apaga el led blanco que ya no es necesario
//----------------------------------------------------------------------------------
//  en este espacio con if segun un parametros se veria que colores van a ser  

//-----------------------------------------------------------------------------------
// Envia el color(en este caso como aun no hice el if pongo el rgb mejorado)
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
}
//***********************************************************************************
int m_distancia()
{
    dl = 0;//resetea el tiempo del contador
//------------------------------------------------------------
    int duracion, aux = 0;
    byte error = 0;
//------------------------------------------------------------
//  saca un promedio en un tiempo de 50ms    
//-----------------------------------------------------   
    for (byte veces = 0; veces < 10; veces++)
    {
//-----------------------------------------------------        
//      mide la distancia
//----------------------------------------------------- 
        digitalWrite(TRIG, HIGH);
        delay(1);
        digitalWrite(TRIG, LOW);
        duracion = pulseIn(ECO,HIGH);
//----------------------------------------------------- 
//      se fija de que no haya errores
//----------------------------------------------------- 
        if(duracion > 0)
            aux += duracion/58.2;
        else
            error++;
        delay(5);
    }
//----------------------------------------------------- 
//  segun los erroes que haya da un resultado
//----------------------------------------------------- 
    if(error < 3)
    {
        aux = aux/(10 - error);
        return (aux);
    }
    else
        return 999;
//------------------------------------------------------------
}
//***********************************************************************************
void s_ultra()
{
    if(digitalRead(boton_d))
    {
        distancia = m_distancia();
        Serial.println(distancia);
    }
    if(dl > 1000 && !md_ahorro)
    {
        distancia = m_distancia();
        if(distancia < 70)
        {
            analogWrite(buzzer, 5);
            Serial.println("cuidado");
            delay(500);
            analogWrite(buzzer, 0);
        }
    }
}
//***********************************************************************************