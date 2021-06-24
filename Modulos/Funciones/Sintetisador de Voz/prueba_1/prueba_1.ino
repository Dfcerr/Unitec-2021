#include "talkie.h"

Talkie voice;

int boton_1 = 4;
int boton_2 = 5;

const uint8_t uno[] PROGMEM = {0x8A,0xA1,0xA5,0xCF,0xA1,0x12,0x07,0x96,0x85,0xDE,0x46,0xAF,0x9B,0x38,0x9A,0x7B,0x42,0x22,0x5A,0xE2,0x68,0xE8,0x49,0x8E,0x72,0x85,0x17,0xA6,0xBB,0x54,0xAA,0xB5,0x24,0x0B,0xDA,0x12,0xB3,0x36,0xD2,0x22,0x70,0x3C,0xC2,0x6D,0x4B,0x9B,0xC6,0xB1,0x34,0x2F,0x2D,0xAB,0x12,0xC6,0xDB,0x3D,0x17,0xB1,0x2A,0x18,0xAF,0xF0,0xD2,0x8A,0xAC,0xB9,0xB0,0x7C,0x71,0x2B,0x83,0xD7,0xA2,0xCA,0x46,0xA5,0xF2,0xCE,0x9A,0xB2,0x52,0x96,0xDA,0x46,0x2F,0xCA,0x4A,0x95,0x6A,0x9D,0x23,0x39,0xDA,0x51,0x68,0x7C,0xF0,0x62,0x4F,0x47,0xA1,0x49,0xDA,0x9A,0xDD,0x5C,0xB9,0x26,0x1A,0x2B,0x76,0x77,0x65,0xEA,0xA8,0xB4,0xCC,0x2C,0x91,0xAA,0x82,0xF1,0x30,0x4D,0x5B,0xA2,0x8C,0x26,0x52,0x25,0x62,0xB3,0x3D,0x2B,0x4F,0xD5,0x48,0xC4,0xF6,0x24,0x32,0x5D,0x22,0x31,0xE1,0x33,0xD7,0x6C,0x8E,0xC4,0x48,0x6C,0x92,0xA3,0xDD,0x13,0x3F};
const uint8_t dos[] PROGMEM = {0xE8,0x32,0x42,0x6F,0xD4,0x68,0x93,0xC2,0x08,0xFD,0x64,0x67,0x45,0x0A,0x66,0xE2,0x5C,0x42,0x11,0x2B,0xA4,0xB2,0x73,0x4B,0x85,0xA2,0xB0,0xDC,0x36,0x46,0x6B,0x96,0x3C,0x09,0x69,0xE9,0x98,0xD4,0xF2,0xA8,0xB5,0xA5,0x62,0x72,0x2B,0x82,0xF1,0xD5,0xC8,0xC9,0xA5,0xB0,0xA1,0xD6,0x2C,0x26,0x97,0xD2,0xDB,0x1A,0xB3,0x98,0x9C,0x2A,0x6F,0x6B,0xD8,0x72,0xB2,0xAB,0xBD,0xC9,0x61,0x8D,0xC9,0xAE,0x4E,0xD2,0xD6,0xD4,0x26,0x9B,0x32,0x29,0x6B,0xB3,0xA8,0xED,0xCA,0xC2,0x23,0xD4,0x6D,0x6E,0x02,0xA6,0x8A,0x2C,0xC0,0x09,0x5E,0x0D,0xB8,0xCD,0xAB,0x00,0xAF,0x47,0x35,0xE0,0xB6,0xA8,0x00,0xDC,0x92,0xF5};



void setup() 
{
  Serial.begin(9600);
  pinMode(boton_1, INPUT);
  pinMode(boton_2, INPUT);
}
void loop()
{
  if(digitalRead(boton_1))
  {
    Serial.println("uno");
    voice.say(uno);
  }

  if(digitalRead(boton_2))
  {
    Serial.println("dos");
    voice.say(dos);
  }
  delay(200);
}