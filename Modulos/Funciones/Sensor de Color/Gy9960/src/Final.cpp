#include <SparkFun_APDS9960.h>
#include <Wire.h>

#define led 4
#define boton 5
#define buzzer 6

SparkFun_APDS9960 apds = SparkFun_APDS9960();

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
        crgbc();    
        Serial.println("*************************************");
    }
}

//***********************************************************************************************************
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
//***********************************************************************************************************