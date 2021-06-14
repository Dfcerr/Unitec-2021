#include <SparkFun_APDS9960.h>
#include <Wire.h>

#define boton 5

SparkFun_APDS9960 apds = SparkFun_APDS9960();

void setup() 
{
    Serial.begin(9600);
//  iniciacion de la libreria para el GY9960
//**********************************************************************
    apds.init();
    apds.enableLightSensor(false);
//**********************************************************************
}

void loop() 
{
    delay(400); 

    if(digitalRead(boton))
    {
        for(int a = 0; a < 4; a++)
          que_color();    
        Serial.println("*************************************");
    }

}
//***********************************************************************************************************
void que_color()// en esta funcion se tiene que intentar determinar un color en concreto
{
//  saca el valor ambiental
    float Ambiental = crgbc(0);
//  convierte este valor de 0 a 255
    Serial.println(map((((Ambiental/2.9)/crgbc(1))*100), 0, 100, 0, 255));
    Serial.println(map((((Ambiental/2.9)/crgbc(2))*100), 0, 100, 0, 255));
    Serial.println(map((((Ambiental/2.9)/crgbc(3))*100), 0, 100, 0, 255));
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