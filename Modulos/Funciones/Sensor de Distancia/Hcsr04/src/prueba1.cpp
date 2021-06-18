// Hola :D
#define TRIG 10
#define ECO  9
#define boton_d  8

int distancia;
 
void setup() 
{
	pinMode(TRIG, OUTPUT);
    Serial.begin(9600);
} 
void loop()
{   
    if(digitalRead(boton_d))
        distancia = d_ultra();
    
    Serial.println(distancia);
    delay(200);
}

int d_ultra()
{
    int duracion;
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    duracion = pulseIn(ECO,HIGH);
    return (duracion / 58.2);
}