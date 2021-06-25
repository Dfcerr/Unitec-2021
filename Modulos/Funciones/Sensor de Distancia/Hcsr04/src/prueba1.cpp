// Hola :D
#define TRIG 10
#define ECO  9
#define boton_d  8
#define buzzer 6

int distancia;
int dl = 0;
int mh = 1;
void setup() 
{
	pinMode(TRIG, OUTPUT);
    Serial.begin(9600);
} 
void loop()
{   
    s_ultra();
    delay(200);dl += 200;
}

int m_distancia()
{
    dl = 0;//resetea el tiempo del contador
//------------------------------------------------------------
    int duracion, aux = 0;
    byte error = 0;
//------------------------------------------------------------
//  saca un promedio en un tiempo de 50ms    
//-----------------------------------------------------   
    for (byte veces = 0; veces < 10; veces++)
    {
//-----------------------------------------------------        
//      mide la distancia
//----------------------------------------------------- 
        digitalWrite(TRIG, HIGH);
        delay(1);
        digitalWrite(TRIG, LOW);
        duracion = pulseIn(ECO,HIGH);
//----------------------------------------------------- 
//      se fija de que no haya errores
//----------------------------------------------------- 
        if(duracion > 0)
            aux += duracion/58.2;
        else
            error++;
        delay(5);
    }
//----------------------------------------------------- 
//  segun los erroes que haya da un resultado
//----------------------------------------------------- 
    if(error < 3)
    {
        aux = aux/(10 - error);
        return (aux);
    }
    else
        return 999;
//------------------------------------------------------------
}
void s_ultra()
{
    if(digitalRead(boton_d))
    {
        distancia = m_distancia();
        Serial.println(distancia);
    }
    if(dl > 1000 && !mh)
    {
        distancia = m_distancia();
        if(distancia < 70)
        {
            analogWrite(buzzer, 5);
            Serial.println("cuidado");
            delay(500);
            analogWrite(buzzer, 0);
        }
    }
}