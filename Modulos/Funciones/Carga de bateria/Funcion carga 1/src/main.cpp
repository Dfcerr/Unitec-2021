#include <Arduino.h>

int tp4056 = 12;//Entrada del modo tp4056
int boc = 11; //bateria o cargador

int cod = 0; // carga o descarga (esta variable luego puede ser usada para el modo ahorro de bateria)


void setup() 
{
  Serial.begin(9600);
  pinMode(boc, OUTPUT);
}

void loop() 
{
    carga_o_descarga();//llama a la funcion
    delay(1000);
}

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