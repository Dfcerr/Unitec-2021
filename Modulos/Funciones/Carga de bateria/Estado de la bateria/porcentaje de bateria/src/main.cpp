#include <Arduino.h>

#define at 0// pin analogico de tension
#define mh 10// entrada para forzar modo ahorro
#define tp4056 12;//Entrada del modo tp4056

int por_bat;
bool md_ahorro;
float porcentaje;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  
  Serial.println(porcentaje_bateria());
  delay(1000);
}
//***********************************************************************************
int porcentaje_bateria()
{
  if(digitalRead(tp4056))
  {
    
//saca el porcentaje de bateria  
    porcentaje = map(map(analogRead(at), 0, 1023, 0, 500), 320, 420, 0, 100);// el primer map saca la tension y segundo el porcentaje
//  los valores de 320 a 420 serian de 3.2 a 4.2 v, esto baria en funcion de la ocilacion de nuestra bateria, este es el normal
    return porcentaje;
  }

}

}
//***********************************************************************************
void modo_ahorro()
{
  por_bat = porcentaje_bateria();

  if(mh)
  {
    md_ahorro = 1;
    return;
  }

  if(digitalRead(tp4056))
  {
    md_ahorro = 0;
    return;
  }


}
//***********************************************************************************