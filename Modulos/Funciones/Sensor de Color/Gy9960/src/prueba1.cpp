
#include <Melopero_APDS9960.h>

Melopero_APDS9960 device;

void setup() 
{
  Serial.begin(9600);

// iniciacion de la libreria para el GY9960
//**********************************************************************
  device.init();
  device.reset();
  device.enableAlsEngine();
  device.setAlsIntegrationTime(450);
  device.updateSaturation();
  device.wakeUp();
//**********************************************************************
}

void loop() 
{
  delay(450); 

  device.updateColorData();//toma lo que capta el sensor
//escribe la saturacion, esto es clave y solo lo vi en esta libreria
  Serial.println("valor de saturacion: ");
  Serial.println(device.alsSaturation);
// usando la saturacion y el valor que da, saca un valor constante entre 1-0, esto facilitara saber que color es con exactitud
  float r = (((float) device.red) / (float) device.alsSaturation);
  float g = (((float) device.green) / (float) device.alsSaturation);
  float b = (((float) device.blue) / (float) device.alsSaturation);
  float c = (((float) device.clear) / (float) device.alsSaturation);
// escribe los valores
  Serial.println("Valores:");
  printColor(r,g,b,c);
}

void printColor(float r, float g, float b, float c)
{
  Serial.print("R: ");
  Serial.print(r);
  Serial.print(" G: ");
  Serial.print(g);
  Serial.print(" B: ");
  Serial.print(b);
  Serial.print(" C: ");
  Serial.println(c);
}
