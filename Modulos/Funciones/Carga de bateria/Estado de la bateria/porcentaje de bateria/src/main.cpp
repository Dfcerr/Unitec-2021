#include <Arduino.h>

#define at 0// pin analogico de tension

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  
  Serial.println(porcentaje_bateria());
  delay(1000);
}

int porcentaje_bateria()
{
  float porcentaje;
//saca el porcentaje de bateria  
  porcentaje = map(map(analogRead(at), 0, 1023, 0, 500), 320, 420, 0, 100);// el primer map saca la tension y segundo el porcentaje
// los valores de 320 a 420 serian de 3.2 a 4.2 v, esto baria en funcion de la ocilacion de nuestra bateria, este es el normal
  return porcentaje; 
}