#include <SparkFun_APDS9960.h> 
#include <Wire.h>

#define led 4
#define botonColor 5
#define buzzer 6

SparkFun_APDS9960 apds = SparkFun_APDS9960();

void setup() 
{
  Serial.begin(9600);
  pinMode(botonColor, INPUT_PULLUP);
//color
  apds.init();
  apds.enableLightSensor(false);
//proximidad
  apds.enableProximitySensor(false);
  apds.setProximityGain(PGAIN_1X);
}

void loop() 
{
    delay(400); 
    if(!digitalRead(botonColor))
        determinarColor();    
}

//***********************************************************************************************************
void determinarColor()// en esta funcion se tiene que intentar determinar un color en concreto
{
  digitalWrite(led, HIGH);// prende un led blanco para mejorar la lectura
  delay(200);//para que bi se active el proceso de salir de la funcion
// variables declaradas 
  int cont = 0;
  uint8_t proximidad;
  uint16_t R;
  uint16_t G;
  uint16_t B;
  uint16_t A;
  float ambiental;
//se fija que este a una distancia optima  
  while(cont<40)//espera 2s
  {
    apds.readProximity(proximidad);// lee la distancia del 9960
    analogWrite(buzzer, 0);//apaga el indicador para que vibre pausadamente
    
    if(!digitalRead(botonColor)){//si vuelve a presionar el boton sale de la funcion
      digitalWrite(led, LOW);// prende un led blanco para mejorar la lectura
      return;
    }
    
    if(proximidad >= 255)// si esta esta en estos parametros empieza a contar por 2s
      cont++;

    else{// si se sale del rango resetea el contador
      cont = 0;// reset del contador de us
      analogWrite(buzzer, 200);// indica que no esta en posicion
    }
    delay(50);
  }
  analogWrite(buzzer, 0);// si todo salio bien apaga el indicador
//------------------------------------------------------------
// saca los colores puros
  apds.readAmbientLight(A);//  saca el valor ambiental
  apds.readRedLight(R); 
  apds.readGreenLight(G); 
  apds.readBlueLight(B); 
//------------------------------------------------------------
//  saca el valor ambiental
  ambiental = A;
  //map((((R/ambiental))*300), 0, 100, 0, 255)
  R = map((((R/ambiental))*300), 0, 110, 0, 255);//  convierte este valor de 0 a 255
  G = map((((G/ambiental))*300), 0, 125, 0, 255);
  B = map((((B/ambiental))*300), 0, 105, 0, 255);;
  digitalWrite(led, LOW);// apaga el led blanco que ya no es necesario
// Envia el color(en este caso como aun no hice el if pongo el rgb mejorado)

  if (R >= G && R >= B)
    Serial.println("rojo");
  if (G >= R && G >= B)
    Serial.println("verde");
  if (B >= G && B >= R)
    Serial.println("azul");

  Serial.println(ambiental);
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);

}

//***********************************************************************************************************