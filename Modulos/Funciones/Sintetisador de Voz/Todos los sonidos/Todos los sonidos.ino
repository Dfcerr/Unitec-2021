#include "talkie.h"

Talkie voice;

#define boton_1 6
#define boton_2 7

const uint8_t Azul [] PROGMEM = {0x47,0xAD,0x21,0xC2,0x46,0xAC,0x1C,0xAD,0xC4,0x48,0x1F,0xB1,0x7D,0x8C,0x12,0x23,0xBD,0xC5,0xCE,0x31,0x4B,0x88,0xB0,0x11,0x3B,0xCD,0xCA,0xCE,0x43,0x87,0xEC,0x38,0xA7,0x4A,0x73,0x6A,0xB1,0x23,0xDA,0xEE,0x3B,0xB5,0x95,0x25,0xB1,0xBA,0xEA,0x2C,0x13,0x92,0xE8,0xEA,0xE5,0xDD,0xD5,0x65,0x8A,0xAE,0xAF,0x0B,0xB3,0x54,0x92,0xC4,0x2C,0x5D,0xBD,0xDA,0xF6,0x10,0xB3,0xF6,0xB0,0x1E,0x5B,0x43,0x4C,0x26,0x5D,0xB3,0x63,0x37,0x31,0xEA,0x0E,0xB1,0x0E,0xD3,0x24,0xEF,0xC7,0xD9,0x27,0x72,0x51,0x6C,0xD8,0x14,0x9B,0xC8,0x4D,0xB3,0xB1,0x4D,0x6B,0x43,0x35,0xC3,0x85,0x74,0xEB,0x8D,0xD2,0xCC,0xE0,0x35,0x62,0x2A,0x6E,0x72,0xA3,0x61,0x8B,0xCD,0xD0,0xCE,0x37,0x3A,0xB2,0x2E,0x45,0xBB,0x40,0xEA,0xAA,0xDA,0xA4,0xAA,0x42,0x69,0x2B,0xB3,0x54,0x29,0x3C};
const uint8_t Cuidado[] PROGMEM = {0x48,0xAB,0xB2,0x23,0xD4,0x1D,0x0B,0x29,0xAD,0x55,0x8F,0xB0,0xA3,0x34,0x99,0x87,0x39,0x26,0x74,0xD0,0x74,0x58,0x67,0x9B,0xC8,0x49,0x73,0xAE,0x4D,0x7D,0x43,0x37,0x2D,0x49,0x77,0xB7,0x89,0xD2,0x8C,0x2E,0xD1,0xB3,0x3A,0x56,0x33,0x87,0x46,0xA9,0x2D,0xD9,0xC5,0xEA,0x02,0xAD,0xD7,0x65,0x25,0xAB,0x0B,0xD4,0x3E,0x73,0x94,0xEC,0x26,0xD1,0xE3,0xC2,0x96,0x72,0x13,0x23,0xCF,0x4E,0x47,0xC2,0x0A,0xCC,0x2C,0x3B,0x6D,0x17,0x23,0x29,0x8B,0x38,0xB3,0xBD,0xB4,0x6C,0x3D,0x6A,0xC5,0xD1,0x51,0x8A,0x8B,0xC8,0x11,0x3B,0x47,0x2A,0x31,0x33,0x5B,0x9C,0x1C,0x3E,0xA7,0xAA,0x68,0x71,0x7A,0xB8,0x9C,0x3B,0xA3,0x35,0xC9,0x61,0x4B,0xAA,0x88,0xD1,0x38,0x8B,0xCD,0xB1,0x22,0x86,0xED,0x0C,0x36,0xC5,0xF0,0x1C,0x72,0x1A,0xB8,0xE4,0xDD,0x7C,0x25,0x2A,0x93,0xBC,0xF0,0x88,0x2A,0x5B,0x81,0x8D,0x3E,0xCC,0x57,0x6D,0x0F,0x36,0xC6,0xF4,0x58,0x73,0xB2,0xB8,0x18,0xCB,0x6C,0x43,0xC9,0xE0,0x53,0x6C,0x97,0x0D,0x25,0x4D,0x88,0xA5,0x4D,0x26,0x14,0x17,0x31,0xD4,0x52,0xDD,0x50,0x52,0xA4,0x50,0x5B,0x79,0xC2,0x71,0x93,0x43,0x4D,0xB1,0x0D,0xD9,0x4D,0x8E,0xCD,0x45,0xDF,0x15,0x37,0x39,0x76,0x13,0x3F,0x57,0x3C,0x94,0x58,0x53,0xE5,0x42,0xF1,0x50,0x63,0x29,0xE5,0x4D,0xC5,0x4D,0x8B,0xAD,0x44,0xAE,0x98,0x34,0x33,0xD6,0x12,0xBD,0x46,0x5A,0x9C,0xD8,0x93,0x75,0x87,0x6E,0xF1,0x62,0x2B,0xA1,0x1D,0x7A,0xC9,0x0F,0x3D,0x85,0x77,0x90,0x85,0x20,0x4C,0x67,0xBD,0x44,0xE2,0xA2,0xB0,0x95,0xFD,0x0A,0xB1,0x89,0xFD,0x74,0xF2,0x29,0xC4,0x2A,0x8E,0xC7,0x49,0x2A,0x15,0xC3,0x03};
const uint8_t Modo_ahorro_activado[] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x54,0x98,0xC6,0x33,0x33,0xB6,0x51,0x49,0x0A,0xAD,0xAC,0x26,0x4E,0xA1,0xA1,0x34,0xAA,0xD2,0x24,0xD9,0xF8,0x11,0xA9,0x70,0xDC,0xC4,0x18,0x8F,0x79,0x5A,0x76,0xE3,0x53,0x38,0xA1,0x6D,0x39,0x8D,0x4D,0xE9,0x58,0xB6,0xA9,0x0E,0x36,0xD5,0x61,0xBE,0xA6,0xDD,0xD8,0x98,0x9B,0xE5,0xDD,0xB6,0x63,0x53,0x49,0x96,0x75,0x3B,0x8A,0x0E,0xA2,0x5C,0x33,0x63,0x17,0x2A,0xC6,0x14,0x5D,0x93,0x3D,0xE8,0x18,0x4B,0x74,0x42,0xD6,0x60,0x62,0x6C,0xE3,0x6D,0x4B,0x8D,0x8B,0xAD,0x44,0xAF,0xE4,0x0C,0x31,0x96,0x56,0xDD,0xA4,0xB3,0x94,0x54,0xD2,0xF4,0x5C,0xC9,0x32,0x72,0x4E,0xD3,0x0D,0x39,0xCB,0x2A,0xA9,0x5C,0xD6,0x65,0x2F,0xA7,0x94,0x74,0xDB,0x90,0xBD,0x9C,0x5C,0xD2,0x75,0x43,0xF1,0x70,0x72,0x2D,0xE3,0x29,0xC6,0xCD,0x49,0xB9,0x55,0xA6,0x65,0x17,0x33,0xE6,0x56,0xDA,0xA1,0x53,0xB4,0x58,0x5B,0x68,0x87,0x6A,0x51,0x42,0x5E,0xA5,0x19,0xBA,0x45,0x0A,0x6D,0x98,0x77,0xE4,0x34,0x31,0x8E,0x12,0x99,0xB1,0xD2,0xC4,0x50,0xC2,0x65,0xD2,0x4E,0x92,0x42,0xE1,0xF2,0x76,0x3B,0x49,0x0A,0x49,0xB2,0x2A,0x43,0x07,0x29,0x46,0x8D,0x1C,0x8F,0x5C,0xE4,0x90,0xA5,0x62,0xA2,0x4C,0x53,0x42,0xB6,0x88,0x8E,0xA8,0x43,0x8D,0x21,0x5D,0xBA,0xAC,0x2C,0x2D,0xA5,0x34,0x9D,0x96,0xB3,0xCC,0x1C,0xC3,0x6D,0x5A,0xC9,0xB2,0x8B,0x0F,0xB7,0x2E,0xD9,0xCD,0x29,0x46,0x43,0xA7,0x64,0x0B,0xBF,0x29,0x4E,0xF5,0x74,0x64,0xC6,0x51,0x22,0x33,0xDD,0x0E,0x7B,0x46,0x4D,0x73,0x71,0xD9,0x28,0x9C,0xC1,0xD8,0x8D,0x65,0xA1,0x63,0xDA,0xF2,0x30,0x95,0xED,0x8C,0x2A,0xD9,0xCD,0x35,0x4D,0x32,0xBB,0x40,0xCB,0x33,0x5B,0xC5,0xEA,0x02,0xAD,0x36,0x6C,0x16,0xBB,0x4B,0xD4,0x9E,0xB4,0xED,0x9C,0xC2,0x38,0xC2,0xCB,0xB1,0x72,0xA3,0x70,0x53,0xAD,0x38,0xC5,0x4C,0xDE,0xDC,0x26,0xE5,0x2C,0x33,0x7B,0x0F,0xDF,0x90,0x7D,0xCC,0x12,0x23,0x7C,0x42,0xF1,0xB1,0x4A,0xCC,0xB4,0x31,0xD9,0xC7,0x2E,0x29,0x22,0xD6,0x64,0x2F,0xB7,0xC4,0x0C,0x5B,0xB5,0x3D,0xBC,0x12,0x22,0x7C,0xC5,0x72,0xF1,0x73,0x70,0xF7,0xA3,0xB0,0x26,0x48,0xC6,0x5C,0xDB,0x2D,0xA9,0x20,0x58,0x37,0x9B,0x60,0x1C,0xC2,0xE0,0x3D,0x74,0x95,0x95,0x8B,0x42,0x74,0xD7,0x71,0x46,0x26,0x0E,0x39,0x84,0xAB,0x24,0xAB,0x24,0xEB,0x31,0x94,0x90,0xC2,0xB2,0x62,0x2E,0xB4,0x22,0x11,0x4A,0xBA,0xAC,0xCC,0xB2,0x24,0x68,0x1F,0xBA,0xA2,0x32,0x6C,0xA3,0x71,0x98,0xF6,0x0A,0x77,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0};
const uint8_t Modo_ahorro_desactivado[] PROGMEM = {0x46,0xC5,0xB9,0xAC,0xB2,0x92,0x18,0x85,0xA4,0x90,0xCE,0x6C,0x1A,0x64,0x1E,0x5A,0xBC,0x32,0x4E,0x13,0x43,0x38,0xE6,0x2E,0xDB,0x4D,0x48,0xE1,0x84,0x66,0xE4,0x0C,0x2E,0xE5,0x63,0xDE,0x96,0x3C,0xB8,0xD4,0x86,0x74,0x5B,0x4A,0xE3,0x62,0x1E,0x91,0x2B,0xC5,0x81,0x4B,0xB1,0x85,0x36,0xE5,0x28,0x3A,0xA8,0x32,0xCD,0xB2,0x5D,0xE8,0x18,0x52,0x75,0xD5,0x4E,0xA3,0x63,0x28,0x95,0x0D,0xCB,0x8D,0x89,0xB1,0x8D,0xB7,0x25,0x37,0x3E,0xB6,0x12,0xDD,0x52,0x32,0xC4,0x54,0xCA,0x6C,0x43,0xF1,0x52,0x72,0x49,0xB3,0x75,0xC7,0xCB,0x28,0x25,0xCD,0xD6,0x15,0x1F,0xAB,0xE4,0x0C,0x5D,0x53,0xBC,0xEC,0x92,0xCB,0x75,0x83,0xF1,0x70,0x72,0x2E,0x97,0x49,0xC6,0xC3,0xC9,0x3D,0x45,0xA6,0xE4,0x34,0x27,0xE5,0x56,0x9E,0x66,0x5A,0xAC,0x58,0x4B,0x64,0x87,0x6E,0x31,0x62,0x19,0xE6,0x59,0xAA,0x45,0x0D,0x61,0x95,0x66,0xA8,0x15,0x39,0xC4,0x35,0x9C,0xA1,0xD7,0xC4,0xD8,0x5B,0x78,0xC7,0x76,0x13,0x42,0x4B,0x93,0x29,0x3B,0x45,0x88,0x55,0xCA,0x27,0xEC,0x04,0x21,0x46,0x09,0x1F,0x2D,0xED,0xF8,0xE8,0x2C,0xAC,0xC3,0x52,0xE1,0x63,0xD6,0xF0,0x89,0xC8,0x8D,0x8F,0xD9,0xDC,0x2F,0xE2,0x0C,0x21,0xC6,0x72,0xDD,0x70,0xD2,0xA4,0xE0,0xCB,0xF5,0xDC,0x49,0x92,0x83,0x4B,0xD3,0x4B,0x47,0x42,0x73,0xD2,0xDD,0xBA,0x1C,0x17,0x2D,0x1A,0x8F,0xB8,0x70,0x3C,0x8C,0xA2,0xD4,0xFD,0xC2,0xF1,0x30,0xAB,0x12,0xB7,0x0B,0xC7,0xC5,0xAE,0x52,0xDC,0xCE,0x6C,0x1B,0xB7,0x6A,0x36,0x59,0xB5,0xCD,0xBA,0xD6,0x43,0x3A,0x55,0xB2,0xF8,0x5B,0xB7,0x6C,0x57,0xC5,0xC1,0x48,0xD6,0xC3,0x46,0x62,0x0F,0x2B,0x3B,0x4B,0x5B,0x89,0xB2,0x9C,0xE6,0x34,0x6D,0xDC,0x4E,0x71,0x9B,0xA5,0x88,0x4E,0xDB,0x22,0xEA,0x5A,0xC5,0xC3,0x1D,0xAB,0x7F,0xE4,0xCC,0x0C,0xB3,0x4D,0xFE,0x19,0x43,0xC4,0x54,0x36,0xC2,0x47,0x48,0x56,0x33,0x89,0xE8,0xEE,0x2E,0x22,0xC2,0x14,0x3B,0xB3,0x4A,0x72,0x4F,0x75,0x93,0xAC,0x2E,0xD0,0xEA,0x42,0x56,0xB1,0x87,0x42,0xAD,0x0D,0x47,0xC5,0x69,0x12,0xAD,0xA7,0x6C,0x19,0x37,0x32,0xF5,0xF0,0x4C,0x6C,0xEC,0x24,0x5D,0xCC,0x32,0x4E,0x33,0x73,0x30,0xF7,0x29,0x39,0xC7,0x2C,0xC1,0xC3,0xD6,0x15,0x1F,0xB3,0xA4,0x08,0x5B,0xB3,0x73,0xAC,0x92,0x32,0x7D,0x55,0xF6,0x72,0x4A,0x8E,0x88,0x55,0x5B,0xC3,0x2D,0x29,0xC2,0x57,0xC2,0x36,0x3F,0x07,0x0F,0x3B,0x8E,0xEA,0xC2,0xEC,0xCD,0x75,0x5D,0x96,0x08,0x93,0x76,0xB1,0x2C,0xDB,0x21,0x8C,0x41,0x2D,0x56,0x19,0xBB,0x28,0x06,0x77,0x59,0xA3,0x6D,0xA2,0x18,0xC3,0xB0,0x8B,0xB2,0x8A,0x93,0x69,0x41,0x0F,0x2B,0x2C,0x6B,0x62,0x4B,0xD2,0x24,0xA1,0xB3,0xC9,0xA9,0x0C,0x4B,0xF2};
const uint8_t Porciento[] PROGMEM = {0xE0,0x94,0x6A,0xDD,0xCD,0x2D,0x4E,0x52,0x7D,0x6A,0xA7,0x5C,0xB9,0x4D,0x0B,0x7E,0x82,0x62,0xAD,0x0C,0x2D,0xC6,0x36,0x8E,0xB5,0xB2,0x8C,0x94,0xCA,0xA4,0xC6,0xCA,0x30,0x53,0x56,0xB7,0x89,0xA8,0xC1,0xCA,0x45,0xD4,0xDA,0xAB,0x24,0x3B,0x7A,0xF1,0x98,0xB0,0x93,0x9C,0x42,0xDD,0x2C,0xCB,0x96,0x03,0x96,0x0E,0x66,0x6E,0x0F,0xE9,0xB7,0x02,0x19,0x00,0xED,0xE3,0x4D,0xB1,0x42,0x6E,0x23,0x56,0xC9,0x62,0xD7,0x89,0x8A,0xD8,0x39,0x5A,0xBE,0x5B,0x6E,0xE2,0xD4,0xC8,0x75,0x2E,0x7B,0x00,0x53,0x11,0x2F,0x71,0x28,0xB2,0x39,0x93,0xBC,0xA4,0x26,0x39,0x66,0xD5,0xF6,0x91,0x87,0x12,0xAF,0x55,0xD9,0x47,0xE9,0x5A,0xBC,0x46,0x65,0x1F,0x6D,0x18,0x31,0x5F,0x93,0xBD,0x8C,0xAE,0xD5,0x74,0xCD,0x76,0xB3,0x9A,0x12,0x93,0x55,0xC5,0xCE,0x56,0xC6,0x3D,0xCA,0xDC,0x18,0x87,0x79,0x0F,0x2B,0x69,0x24,0x5C,0x94,0x32,0x2C,0x35,0x21,0x71,0x41,0xEE,0xB0,0x50,0x57,0x28,0x08,0xD8,0x23,0x32,0x9D,0x80,0xB3,0xAA,0x33,0x77,0xB3,0x38,0xC5,0x4F,0x4E,0xC3,0xCF,0xE5,0x94,0x20,0x39,0x77,0x9D,0x64,0x92,0xC2,0x90,0xC3,0xB5,0x8B,0x51,0x88,0x43,0x49,0xC7,0x2D,0xC6,0x26,0x09,0xC3,0x58,0xA7,0xE1,0x88,0x34,0xA4,0x24,0xA9,0x90,0xCB,0x92,0x6C,0x56,0x30,0x8D,0x0E,0xCA,0x3A,0xDB,0xA1,0x0E,0xDB,0x0F};
const uint8_t Rojo[] PROGMEM = {0x4D,0x8C,0x49,0x2A,0xC7,0xAB,0x0C,0x31,0x64,0xCD,0x9C,0x88,0xBB,0xC4,0x18,0x32,0xAC,0xD3,0xEE,0x11,0x93,0xAF,0x94,0x6A,0x39,0x4B,0x8E,0xA9,0x4C,0xA6,0x65,0x0F,0x25,0x96,0x12,0x99,0x96,0x33,0xB4,0x58,0x4B,0x64,0x5B,0x71,0x33,0x62,0x69,0xA5,0x6D,0xBA,0xCD,0x0A,0xAD,0x44,0xAE,0x91,0x26,0x27,0xB4,0x10,0xB9,0x42,0xEC,0xDC,0x50,0x5D,0x68,0x4B,0x91,0xF1,0x73,0x38,0x51,0x15,0xD9,0xCA,0x2B,0xE1,0x33,0x33,0x1C,0xAB,0xA3,0xA6,0x8F,0x4A,0x4F,0x64,0xEC,0xEA,0x3F,0x32,0x3D,0xB1,0xB1,0x4B,0x7A,0x2B,0xCB,0x44,0xCE,0x73,0xB1,0x54,0x7D,0x64,0x27,0xCF,0x97,0x32,0xEE,0x95,0x5C,0x7C,0x9F,0xDA,0xA8,0xCE,0x4A,0x0A,0x42,0x2E,0xE5,0x3A,0x31,0x21,0x0A,0x23,0x44,0x76,0xA8,0xB8,0xD8,0xF7,0x60,0x99,0xA1,0x6A,0x12,0x5F,0x93,0xB4,0x8A,0x8E,0x4A,0xBC,0x1A,0x65,0x75,0xC7,0x24,0xAE,0xA2,0xCC,0x45,0xA5,0x3C};
const uint8_t Verde[] PROGMEM = {0x4C,0x85,0xA9,0xBD,0xAB,0x22,0x09,0x15,0xE6,0x8E,0xCA,0x8A,0x1C,0xE4,0xA0,0x2D,0xA2,0x43,0xCA,0x12,0x93,0xB1,0xAC,0x0D,0xC7,0x4B,0xAC,0x46,0xA3,0xCE,0x9C,0x1E,0xB1,0x69,0x8D,0x1A,0xB3,0x73,0xE4,0x66,0x24,0x6A,0x4D,0xF6,0x51,0x9B,0xD6,0xA8,0x75,0xDB,0xC7,0x68,0x5A,0x23,0xD7,0x1D,0x0F,0xB3,0x6A,0x75,0x3F,0x77,0x1C,0xDC,0x64,0xD5,0x7D,0x43,0x76,0x72,0xA3,0xD3,0xF0,0x75,0xC5,0xCE,0x4B,0x56,0x43,0x4F,0x6D,0x0B,0xDF,0x4B,0x33,0x8F,0x96,0xED,0xFC,0xA4,0x34,0x7C,0x52,0x71,0xF1,0xB3,0xD0,0x8E,0x53,0xD9,0x25,0x28,0x42,0xBA,0x4E,0x6C,0xA7,0xB0,0x08,0xEE,0x3E,0x95,0x1D,0xA2,0xCA,0xA9,0x67,0x85,0xB6,0x8B,0x2B,0xC7,0x9A,0x11,0x3A,0x2A,0x1E,0x12,0x22,0x5B,0xE9,0xC0,0x03};
const uint8_t SCCB[] PROGMEM = {0x4C,0xE9,0x31,0x39,0x42,0x6D,0xA1,0xA0,0xC7,0x51,0xCF,0xB0,0x88,0x80,0x11,0xD7,0x58,0xD2,0x47,0x78,0xB5,0x5B,0x34,0x52,0xB3,0xA2,0x32,0xAA,0xA8,0x69,0x49,0x58,0xD5,0xA9,0xAD,0xA1,0x15,0x29,0x51,0x6F,0x8E,0x97,0xD6,0x94,0x78,0xAE,0xD9,0x3E,0x5A,0xD5,0x9A,0xB5,0x6A,0xFB,0x68,0xD5,0x58,0xE6,0x98,0x9D,0xA3,0x55,0x67,0x99,0xE3,0x72,0x8E,0xD6,0xAC,0xA6,0x8F,0x2B,0x29,0x5A,0xD3,0x92,0x5E,0x29,0x87,0x38,0xC3,0xA6,0x79,0x98,0x6D,0x44,0x75,0xDB,0x1E,0x6A,0x8E,0x9C,0x98,0x5F,0x59,0x86,0x5A,0x29,0x6A,0xF0,0xED,0x1A,0x1B,0x65,0xA8,0xD1,0x95,0x6B,0x4C,0x94,0xA5,0xE5,0xE0,0xA6,0x55,0x51,0x9A,0x99,0xBD,0x8A,0x8E,0x5B,0x71,0xA6,0xB2,0xE6,0xB1,0x12,0x3B,0x98,0x56,0x7A,0x7A,0xA9,0xEB,0x61,0x75,0x2D,0x66,0xEB,0xB2,0x87,0x33,0x2C,0xAB,0x4F,0xC8,0x2E,0xCE,0xB0,0x68,0xD9,0x29,0x5B,0x05,0xD3,0x92,0x78,0x84,0x6D,0xB3,0x8D,0x1C,0x19,0x6E,0x4E,0xC4,0x3E,0x72,0xB8,0x9B,0xCA,0x46,0xC0,0xB2,0x6E,0x20,0xB2,0xE6,0x22,0xD4,0xCD,0x71,0x53,0x92,0xB3,0xC8,0xA5,0x38,0x47,0x2E,0x3E,0x22,0x97,0xE3,0x1C,0x29,0xC7,0xCA,0x18,0x71,0x72,0x84,0x9C,0x2B,0x63,0x24,0xC9,0xE1,0x73,0xCA,0xC8,0xD5,0x38,0x8D,0xCB,0x3E,0xC3,0x56,0xEC,0x2A,0x36,0x29,0x37,0xAD,0xB0,0x5D,0xE8,0xE4,0xC3,0xFC,0x59,0xCE,0xA0,0xA3,0x2F,0xB7,0x53,0x39,0x83,0x89,0xA1,0xDD,0x36,0x94,0x2C,0x36,0xF9,0x74,0xBF,0x54,0xBC,0x84,0x6C,0x3C,0x63,0x5D,0xC9,0x92,0xAB,0xD4,0xCC,0x09,0x25,0x47,0x6D,0x4A,0x3C,0x37,0x1C,0x0F,0xA3,0x0A,0xF5,0xDC,0x72,0x5C,0xAC,0x42,0xB5,0x32,0xA7,0x54,0xB2,0x13,0xD3,0xEA,0xAC,0xD0,0xC2,0x2D,0x4C,0x2C,0x23,0x23,0x23,0x60,0x59,0x57,0x55,0x8F,0x94,0x95,0x61,0x76,0x8A,0xD1,0x94,0x44,0x64,0x24,0x5E,0x66,0xD5,0x5A,0x31,0x6E,0xFB,0xD8,0xD5,0x59,0xFA,0x84,0xED,0xE5,0x54,0x67,0x61,0xEB,0x8E,0x8B,0x5B,0xAC,0xB9,0x4C,0xD9,0x6E,0x6E,0xD1,0x92,0x76,0x1A,0x25,0x78,0x55,0x51,0xF9,0xB8,0x6C,0xE3,0x54,0xC1,0x9E,0x15,0x96,0x87,0x5B,0x95,0x54,0x76,0xC8,0x5E,0x5E,0x35,0x96,0xD1,0x21,0x67,0x79,0xD5,0x79,0xDA,0x9A,0xEC,0xE1,0x17,0x1F,0x61,0x6B,0xB2,0x8B,0x9F,0x5C,0xB8,0xAD,0xCB,0x56,0x41,0xE0,0x6E,0x16,0x65,0x3B,0x59,0xC9,0xBB,0xCA,0xA5,0xEC,0x61,0x24,0x1F,0xAA,0x5B,0xB2,0x97,0x9A,0x5C,0x9B,0x74,0xCB,0x5E,0x72,0xF2,0xED,0x92,0x63,0x65,0x49,0x29,0x87,0x6B,0x65,0x94,0x26,0xA5,0x2C,0x91,0xE5,0x61,0x83,0x14,0x82,0x85,0xAF,0xC9,0x0E,0x52,0x08,0x16,0x71,0x62,0xD9,0x28,0x41,0x9B,0xE9,0xA6,0x9D,0x22,0x47,0xEB,0x11,0x6F,0xB6,0x87,0x9C,0xB5,0x79,0xBE,0x39,0x5E,0x4A,0x55,0x1A,0x7E,0xEE,0x68,0xA8,0x45,0x9A,0xDB,0xA6,0xE2,0xA2,0x65,0xE6,0xE1,0xB3,0x41,0x86,0x91,0xB5,0x47,0xAC,0x2B,0x39,0x66,0x75,0xEE,0x7E,0x6E,0xFB,0xD8,0xC5,0x47,0xE8,0x85,0xE2,0xE1,0xE4,0x18,0xAE,0x93,0x8A,0x9C,0x9B,0xB4,0x2B,0x6B,0xC5,0x69,0x4E,0x4E,0x6E,0x3A,0xA5,0x64,0x39,0x25,0x86,0xDB,0xA6,0xE2,0xE5,0x16,0x1F,0x61,0xEB,0x8E,0x9B,0x5B,0xAC,0xB9,0x9D,0xDA,0x11,0x41,0x91,0xEA,0xD2,0x61,0x0B,0xB9,0x43,0x85,0xBA,0xB9,0x13,0x04,0x4E,0x13,0x11,0x6C,0x76,0x82,0x91,0xA5,0x46,0x94,0xBB,0x19,0x56,0x95,0x12,0x79,0x66,0x7B,0x38,0x5D,0xB1,0xC7,0x99,0xED,0xE1,0x74,0xC5,0x1E,0xE7,0xB6,0x93,0xD3,0x04,0xBB,0x6D,0x58,0x0E,0x56,0xE1,0x9C,0x75,0x6E,0xAB,0x58,0x5D,0xA0,0xF7,0x9B,0xA5,0x62,0x0E,0x8E,0xD2,0x67,0x96,0x92,0x35,0x09,0xE9,0x9C,0x4A,0x4E,0xF6,0xA4,0x24,0xF3,0x4A,0x36,0xB8,0x83,0x90,0xDD,0x3B,0xA1,0xE0,0x17,0x2C,0xF5,0x27,0x52,0x52,0x90,0xB9,0xD6,0x0E,0x59,0x4E,0x61,0x56,0xDA,0x99,0x64,0x27,0xC5,0x4D,0x69,0x58,0xAA,0xE5,0x92,0x8C,0x54,0xA1,0xE1,0xB6,0x53,0x3C,0x63,0xA5,0x56,0x26,0x75,0xC0,0x0C,0x5D,0xEA,0x1A,0xAE,0x43,0x2B,0x9A,0xA2,0x7B,0xD8,0x76,0x9D,0x48,0xFC};
const uint8_t SDCB[] PROGMEM = {0x44,0xED,0x3E,0x25,0xCD,0x1C,0xA1,0xB3,0xA7,0x55,0x73,0xB7,0x88,0x80,0xE9,0xD7,0x10,0xD2,0x4B,0xD9,0xF4,0xC4,0x22,0x50,0x5F,0xA5,0xE9,0x11,0x4B,0x71,0xBD,0x94,0xF3,0xA8,0xE4,0xA4,0x45,0x61,0x95,0xA7,0xB6,0x87,0x51,0x84,0x64,0xBE,0xD9,0x5E,0x46,0x53,0xEC,0x79,0xE6,0x78,0x19,0x5D,0x93,0xD7,0xB9,0xE3,0xA5,0x75,0xCD,0x5E,0xE3,0xB6,0x8F,0xD6,0x94,0x66,0x8D,0xD9,0x3E,0x5A,0xD5,0x5E,0x39,0x6A,0xFB,0x68,0xD5,0x7A,0xC4,0xAA,0xED,0x63,0x54,0x17,0x11,0x6B,0xB6,0x97,0x51,0x6C,0x84,0xAF,0xD9,0x0E,0x66,0xB1,0xA6,0x5A,0x29,0x4B,0x99,0x51,0xAA,0x59,0x95,0xED,0xA2,0x65,0xA5,0xE1,0xEF,0x8E,0x87,0x56,0x85,0x44,0xBC,0x27,0x5E,0x46,0x53,0x6C,0xFE,0xE1,0x78,0x98,0x55,0x89,0xFB,0xA5,0xE3,0x64,0x26,0xAD,0x91,0x6B,0x8E,0x95,0xDD,0x8C,0x29,0x8C,0xCB,0x21,0x6B,0xAB,0xE3,0x16,0xA6,0x98,0x00,0x75,0x45,0x13,0xA0,0xB5,0x4A,0xD4,0x0D,0xD7,0x9E,0x6D,0x92,0x40,0x1D,0xF9,0xB6,0x75,0xB8,0x9D,0xA0,0x85,0x90,0xA6,0xBD,0x76,0x9A,0x16,0x6D,0x85,0xF8,0xDA,0x1D,0x46,0xF2,0x65,0x92,0x6B,0x76,0x98,0x39,0xB8,0x49,0x97,0xD5,0x62,0x66,0x2F,0xA2,0xE3,0x51,0x9C,0x29,0xAC,0x47,0xB4,0xC4,0x0A,0xA6,0x51,0x9E,0x59,0xEA,0x78,0x98,0x5D,0x89,0xE9,0x9A,0xEC,0x65,0x0D,0x23,0x6A,0xEB,0xB2,0x87,0x3D,0x2C,0x5B,0x4C,0xD2,0x6E,0xCE,0xF4,0xA8,0x31,0x25,0xDB,0x78,0xD3,0x23,0x67,0x86,0x1D,0x05,0xCC,0x12,0x61,0x80,0x95,0x2B,0x59,0x34,0xF2,0x84,0x87,0xCB,0x46,0xC0,0xF2,0xAE,0x00,0x41,0xCE,0xC6,0x3C,0xCB,0x6D,0x0F,0x39,0x7B,0x8B,0x5A,0x8E,0x7D,0xE4,0x12,0x22,0x73,0x38,0xEE,0x91,0x72,0xCA,0xCC,0x16,0x3B,0x47,0xC8,0xA9,0x33,0x5A,0x92,0x2C,0x2E,0xA7,0x8C,0x1C,0x8D,0xDD,0xB8,0xEC,0x2A,0x6D,0xD9,0x8E,0xE1,0xB3,0x0D,0xD3,0x76,0xC7,0x8A,0x8E,0x26,0xCC,0x26,0x64,0x37,0x3A,0xFA,0xB4,0x58,0x95,0x3B,0xE8,0x18,0xCA,0x6D,0x5C,0xCE,0x60,0xA2,0x6F,0xB7,0x4D,0x25,0x8B,0x4B,0x3E,0xDD,0x27,0x9D,0x2C,0xA1,0x68,0x8F,0xD8,0x50,0xB2,0xA4,0xAA,0x35,0x6A,0x42,0xC9,0x52,0x9B,0x12,0xCF,0x0D,0x3B,0xC3,0x68,0x4A,0x2C,0x2E,0x1C,0x17,0x2B,0x13,0xAB,0xEA,0x0E,0x1D,0xEC,0x42,0xB4,0x3A,0xA3,0x52,0x70,0x32,0x95,0xDE,0x8C,0x48,0xC4,0xCB,0x44,0x34,0x33,0xE2,0x00,0x98,0x69,0x54,0xAF,0x4C,0xB3,0x53,0x8C,0x22,0x35,0x2B,0xDD,0xF6,0x32,0x8A,0xB1,0xF2,0x76,0xDB,0xC7,0xAC,0xDE,0xD2,0x27,0x6C,0x2F,0xAB,0x3A,0x0F,0x5B,0xB7,0x5D,0xEC,0x6A,0xCD,0x79,0xDD,0x4A,0x73,0x8A,0x96,0xB0,0x73,0xDB,0xC9,0xAD,0x8A,0xCB,0x56,0xE3,0x18,0xAF,0x4A,0xAC,0x28,0xB3,0xED,0xEC,0xA6,0xC8,0x2A,0xD3,0x4E,0x73,0xAA,0x92,0x8E,0x0E,0xD9,0xCB,0xAD,0xC6,0xD2,0x3B,0x94,0x2C,0xAF,0xD8,0x48,0x9F,0x90,0x3D,0xBC,0xE2,0x22,0xED,0xD4,0x76,0xF3,0xB3,0x8B,0xD0,0x13,0xDB,0xC9,0xCF,0xD6,0x5D,0xCE,0xEC,0x08,0xDF,0x72,0x77,0xCF,0xB2,0xE5,0xDC,0x64,0xC3,0x74,0x53,0x4E,0xB3,0xA3,0x0F,0xB3,0x4B,0xD9,0xC3,0x48,0xAE,0x5C,0x66,0xE8,0x0E,0x35,0xF9,0x36,0xE9,0x91,0xBA,0xE4,0x14,0xC6,0xA4,0xC6,0xF2,0x12,0x53,0x2E,0xD3,0x6A,0x33,0x83,0x4F,0xD9,0xC2,0x3B,0xE2,0x06,0x21,0x45,0x8E,0x6C,0x8F,0x92,0xC4,0x10,0x2D,0xF3,0xC4,0xB2,0x91,0xBD,0x75,0xB7,0x0D,0x9A,0x4C,0x25,0x76,0xB2,0x2A,0x6C,0x1B,0xC5,0x6B,0xF3,0x18,0x97,0xD5,0xE4,0x68,0x3C,0xEB,0xD5,0xF6,0x52,0x8A,0xD4,0x88,0x57,0xDB,0x4B,0x6D,0x46,0x2C,0xCE,0x15,0x37,0xAD,0x28,0xB5,0xD8,0x94,0x5D,0xB4,0x4C,0xBC,0xA2,0x26,0x70,0x31,0x22,0xAB,0xCA,0xEE,0x30,0xCB,0x28,0xC6,0xC3,0xCF,0x6C,0x1F,0xAB,0xBA,0x08,0x3B,0xB3,0x7D,0xEC,0x12,0x22,0xEC,0x42,0xF1,0x70,0x72,0x8C,0xD0,0x4D,0xC5,0xCE,0x4B,0x36,0x44,0xB4,0xAC,0x38,0x3B,0xF9,0x60,0x8B,0xB2,0x32,0xEC,0x9C,0xDC,0x6D,0x53,0xF1,0x72,0x4A,0x0C,0xB7,0x0D,0xC5,0xCB,0xAD,0x2E,0x42,0xD7,0x1D,0x37,0xB7,0x38,0x73,0x5B,0xB3,0x1D,0xBC,0xA8,0x3C,0x7C,0xCD,0x16,0x09,0x9B,0x76,0x16,0x75,0xC7,0x28,0xEA,0x2A,0x2C,0xDC,0x6D,0x83,0x31,0xB2,0xD4,0xB0,0x51,0x27,0xCD,0x2E,0x52,0x32,0x4E,0x6D,0x0F,0xA7,0x29,0x89,0x5C,0xB7,0x3D,0x9C,0xA6,0x38,0x72,0x43,0x76,0x73,0xBB,0x62,0x8F,0x0B,0xD9,0xC1,0x6D,0x82,0xDD,0x36,0x64,0x3B,0xBB,0x30,0xAE,0x5A,0x97,0x54,0xCC,0x2E,0x30,0xFA,0xCD,0x56,0x31,0x06,0x47,0x9D,0x35,0x4B,0xC9,0x18,0x1C,0x79,0x4F,0x2D,0x27,0x73,0x52,0x92,0x39,0xB5,0x1D,0x80,0x49,0x49,0x82,0x3B,0x29,0xC9,0xBE,0x91,0x09,0x7E,0xC3,0x14,0x7F,0x66,0x39,0xF9,0x19,0x6B,0xEF,0xB0,0x9D,0x14,0x24,0xA1,0x33,0x4D,0x56,0x52,0x50,0x94,0x64,0x37,0x59,0x4E,0x61,0x56,0x51,0x9E,0xA2,0x38,0x45,0xDD,0x9A,0x6B,0x98,0xEC,0x14,0xCF,0x98,0x61,0x6E,0x96,0x43,0x34,0x62,0xA7,0x66,0xC4,0x31,0xC9,0xF4,0x1D,0x5A,0x99,0x86,0xBD,0xC3,0xB5,0xEB,0x64,0x1A,0x04,0x4C,0xDB,0xF6};

byte palabra = 1;
bool clv = 0;
void setup() 
{
    Serial.begin(9600);
    pinMode(boton_1, INPUT_PULLUP);
    pinMode(boton_2, INPUT_PULLUP);
}
void loop()
{
    if(!digitalRead(boton_1))
    {
        palabra++;
        clv = 1;
    }
    else if(!digitalRead(boton_2))
    {
        palabra--;
        clv = 1;
    }

    if(palabra < 1)
        palabra = 10;
    else if(palabra > 10)
        palabra = 1;
    
    if(clv)
    {
        switch (palabra)
        {
        case 1:
            num();
            break;
        case 2:
            Serial.println("Porciento");
            voice.say(Porciento);
            break;
        case 3:
            Serial.println("Rojo");
            voice.say(Rojo);
            break;
        case 4:
            Serial.println("Verde");
            voice.say(Verde);
            break;
        case 5:
            Serial.println("Azul");
            voice.say(Azul);
            break;
        case 6:
            Serial.println("Se a conectado el cargador de la bateria");
            voice.say(SCCB);
            break;
        case 7:
            Serial.println("se a desconectado el cargador de la bateria");
            voice.say(SDCB);
            break;
        case 8:
            Serial.println("Modo ahorro activado");
            voice.say(Modo_ahorro_activado);
            break;
        case 9:
            Serial.println("Modo ahorro desactivado");
            voice.say(Modo_ahorro_desactivado);
            break;
        case 10:
            Serial.println("CUIDADO!!");
            voice.say(Cuidado);
            break;
        }

        clv = 0;
    }

    delay(200);
}

void num()
{
    byte aux, d_1, d_2, d_3;
    byte nu, normal = 0, y = 1;
    nu = map(analogRead(A5), 0, 1024, 0, 100);
    Serial.println(nu);

    aux = nu / 100;
    d_1 = aux;

    aux = nu - (d_1 * 100);
    d_2 = aux /10;

    d_3 = nu - (d_2 * 10);

    switch (nu)
    {
    case 100:
        Serial.print("cien");
        break;
    case 20:
        Serial.print("viente");
        break;
    case 15:
        Serial.print("quince");
        break;
    case 14:
        Serial.print("catorce");
        break;
    case 13:
        Serial.print("trece");
        break;
    case 12:
        Serial.print("doce");
        break;
    case 11:
        Serial.print("once");
        break;
    case 10:
        Serial.print("diez");
        break;
    case 0:
        Serial.print("cero");
        break;
    default:
        normal = 1;
        break;
    }

    if(normal)
    {
//------------------------------------------------
//      decenas
//------------------------------------------------
        switch (d_2)
        {
        case 9:
            Serial.print("noventa");
            break;
        case 8:
            Serial.print("ochenta");
            break;
        case 7:
            Serial.print("setenta");
            break;
        case 6:
            Serial.print("sesenta");
            break;
        case 5:
            Serial.print("cincuenta");
            break;
        case 4:
            Serial.print("cuarenta");
            break;
        case 3:
            Serial.print("treinta");
            break;
        case 2:
            Serial.print("veinti ");
            y = 0;
            break;
        case 1:
            Serial.print("diesi ");
            y = 0;
            break;
        default:
            y = 0;
            break;
        }
//------------------------------------------------
//      usar y?
//------------------------------------------------        
        if(d_3 == 0)
            y = 0;
            
        if(y)
            Serial.print(" y ");
//------------------------------------------------
//      unidades
//------------------------------------------------
        switch (d_3)
        {
        case 9:
            Serial.print("nueve");
            break;
        case 8:
            Serial.print("ocho");
            break;
        case 7:
            Serial.print("siete");
            break;
        case 6:
            Serial.print("sies");
            break;
        case 5:
            Serial.print("cinco");
            break;
        case 4:
            Serial.print("cuatro");
            break;
        case 3:
            Serial.print("tres");
            break;
        case 2:
            Serial.print("dos");
            break;
        case 1:
            Serial.print("uno");
            break;
        default:
            break;
        }
    }
    Serial.println(" porciento");

}