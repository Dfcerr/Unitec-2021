#include <Arduino.h>

#define at 0// pin analogico de tension
#define mh 10// entrada para forzar modo ahorro
#define tp4056 12//Entrada del modo tp4056
#define cc 9//cierre de carga

int md_ahorro;
float porcentaje;
int cod;

void setup() 
{
  Serial.begin(9600);
  pinMode(cc, OUTPUT);// pone en modo salida el cc de la bateria
  digitalWrite(cc, HIGH);//lo activa para que siempre este activado, solo se cierra cuando haga una lectura
}

void loop() 
{
  cod = digitalRead(tp4056);
  
  Serial.println(porcentaje_bateria());

  modo_ahorro();

  
  delay(1000);
}
//***********************************************************************************
int porcentaje_bateria()
{
// si esta en modo carga cierra por un instante el proceso de carga para que este no afecte la lectura
//------------------------------
  if(cod)
    digitalWrite(cc, LOW);
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
  if(digitalRead(tp4056))
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
  if(tm != md_ahorro)
    {
      if(md_ahorro)
        Serial.println("modo ahorro activado");
      else
        Serial.println("modo ahorro desactivado");
    }
}
//***********************************************************************************
