// Hola :D
int TRIG = 10;
int ECO = 9;
int LED = 13;

int duracion;
int distancia;
 
void setup(){
	pinMode(TRIG, OUTPUT);
	pinMode(ECO, INPUT);
	pinMode(LED, OUTPUT);
    Serial.begin(9600);
} 
void loop()
{
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    duracion = pulseIn(ECO,HIGH);
    distancia = duracion / 58.2;
    Serial.println(distancia);
    delay(200); 
    if (distancia <= 20 && distancia >= 0)
    {
        digitalWrite(LED , HIGH);
        delay(distancia * 10);
        digitalWrite(LED, LOW);// 5>0 , MANDE UNA SEÑAL A UN SISTEMA DE VIBRACION.
    }
}
