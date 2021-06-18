#include <Arduino.h>

#define at 0// pin analogico de tension
#define mh 10// entrada para forzar modo ahorro
#define tp4056 12//Entrada del modo tp4056
#define boc 11 //bateria o cargador
#define cc 9//cierre de carga
#define boton_p 8//para dar el porcentaje

bool md_ahorro;
int porcentaje;
bool cod;

void setup() 
{
  Serial.begin(9600);
//Pin mode
//-----------------------------------------------------------------
  pinMode(cc, OUTPUT);
  pinMode(boc, OUTPUT);
//-----------------------------------------------------------------
  digitalWrite(cc, HIGH);//lo activa para que siempre este activado, solo se cierra cuando haga una lectura
}

void loop() 
{
  carga_o_descarga();
  porcentaje_bateria();
  modo_ahorro();
  Serial.print(porcentaje);
  Serial.println("%");
  
  delay(1000);
}
//***********************************************************************************
int porcentaje_bateria()
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