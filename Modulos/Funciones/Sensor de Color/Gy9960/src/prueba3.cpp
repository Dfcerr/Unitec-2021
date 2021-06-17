#include <SparkFun_APDS9960.h>
#include <Wire.h>

#define led 4
#define boton 5
#define buzzer 6

SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint8_t proximidad = 0;

void setup() 
{
  Serial.begin(9600);
//iniciacion de la libreria para el GY9960
//**********************************************************************
//color
  apds.init();
  apds.enableLightSensor(false);
//proximidad
  apds.enableProximitySensor(false);
  apds.setProximityGain(PGAIN_4X);
//**********************************************************************
}

void loop() 
{
    delay(400); 
    
    if(digitalRead(boton))
    {
        que_color();    
        Serial.println("*************************************");
    }
}

//***********************************************************************************************************
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
  R = map((((Ambiental/2.9)/crgbc(1))*100), 0, 100, 0, 255);
  G = map((((Ambiental/2.9)/crgbc(2))*100), 0, 100, 0, 255);
  B = map((((Ambiental/2.9)/crgbc(3))*100), 0, 100, 0, 255);
  digitalWrite(led, LOW);// apaga el led blanco que ya no es necesario
//----------------------------------------------------------------------------------
//  en este espacio con if segun un parametros se veria que colores van a ser  

//-----------------------------------------------------------------------------------
// escribe el color (en este caso como aun no hice el if pongo el rgb mejorado)
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
}
//***********************************************************************************************************
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
//*********************************************************************************************************** 