#include <Arduino.h>

#define at 0// pin analogico de tension
#define mh 10// entrada para forzar modo ahorro
#define tp4056 12//Entrada del modo tp4056
#define boc 11 //bateria o cargador
#define cc 9//cierre de carga
#define boton_p 8//para dar el porcentaje

bool md_ahorro;
bool cod = 0;

void setup() 
{
  Serial.begin(9600);
//Pin mode
//-----------------------------------------------------------------
  pinMode(boton_p, INPUT_PULLUP);
  pinMode(cc, OUTPUT);
  pinMode(boc, OUTPUT);
//-----------------------------------------------------------------
  digitalWrite(cc, HIGH);//lo activa para que siempre este activado, solo se cierra cuando haga una lectura
}

void loop() 
{
  bateria(0);
  
  if(!digitalRead(boton_p))
  {
    Serial.print(bateria(1));
    Serial.println("%");
  }

  delay(300);
}
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