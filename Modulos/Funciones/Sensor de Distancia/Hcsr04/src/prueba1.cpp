// Hola :D
#define TRIG 10
#define ECO  9
#define botonDistancia  5
#define buzzer 6

int distancia;
bool modoAhorro = 0;

unsigned long axuMillis;

void setup() 
{
    pinMode(TRIG, OUTPUT);
    pinMode(botonDistancia, INPUT_PULLUP);
    axuMillis = millis();
    Serial.begin(9600);
} 
void loop()
{   
    s_ultra();
    delay(200); 
}
//***********************************************************************************
int m_distancia()
{
    int duracion, aux = 0;
    uint8_t error = 0;
//  saca un promedio en un tiempo de 100ms
    for (byte veces = 0; veces < 10; veces++)
    {
//      mide la distancia
        digitalWrite(TRIG, HIGH);
        delay(1);
        digitalWrite(TRIG, LOW);
        duracion = pulseIn(ECO,HIGH);
//      se fija de que no haya errores
        if(duracion > 0)
            aux += duracion/58.2;
        else
            error++;
        delay(100);
    }
//  segun los erroes que haya da un resultado
    if(error < 3)
    {
        aux = aux/(10 - error);
        return (aux);
    }
    else
        return 999;
}
//***********************************************************************************
void s_ultra()
{
    if(!digitalRead(botonDistancia))
    {
        distancia = m_distancia();
        Serial.println(distancia);
    }
    if(!modoAhorro && (millis() - axuMillis) > 1000)//si a pasado 1s toma una medida
    {
        axuMillis = millis();
        distancia = m_distancia();
        if(distancia < 70)
        {
            analogWrite(buzzer, 200);
            Serial.println("cuidado");
            delay(500);
            analogWrite(buzzer, 0);
        }
    }
}
//***********************************************************************************