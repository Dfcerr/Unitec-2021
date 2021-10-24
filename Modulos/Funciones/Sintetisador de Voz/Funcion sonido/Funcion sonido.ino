#include "talkie.h"

Talkie voice;

const uint8_t azul [] PROGMEM = {0x47,0xAD,0x21,0xC2,0x46,0xAC,0x1C,0xAD,0xC4,0x48,0x1F,0xB1,0x7D,0x8C,0x12,0x23,0xBD,0xC5,0xCE,0x31,0x4B,0x88,0xB0,0x11,0x3B,0xCD,0xCA,0xCE,0x43,0x87,0xEC,0x38,0xA7,0x4A,0x73,0x6A,0xB1,0x23,0xDA,0xEE,0x3B,0xB5,0x95,0x25,0xB1,0xBA,0xEA,0x2C,0x13,0x92,0xE8,0xEA,0xE5,0xDD,0xD5,0x65,0x8A,0xAE,0xAF,0x0B,0xB3,0x54,0x92,0xC4,0x2C,0x5D,0xBD,0xDA,0xF6,0x10,0xB3,0xF6,0xB0,0x1E,0x5B,0x43,0x4C,0x26,0x5D,0xB3,0x63,0x37,0x31,0xEA,0x0E,0xB1,0x0E,0xD3,0x24,0xEF,0xC7,0xD9,0x27,0x72,0x51,0x6C,0xD8,0x14,0x9B,0xC8,0x4D,0xB3,0xB1,0x4D,0x6B,0x43,0x35,0xC3,0x85,0x74,0xEB,0x8D,0xD2,0xCC,0xE0,0x35,0x62,0x2A,0x6E,0x72,0xA3,0x61,0x8B,0xCD,0xD0,0xCE,0x37,0x3A,0xB2,0x2E,0x45,0xBB,0x40,0xEA,0xAA,0xDA,0xA4,0xAA,0x42,0x69,0x2B,0xB3,0x54,0x29,0x3C};
const uint8_t cuidado[] PROGMEM = {0x48,0xAB,0xB2,0x23,0xD4,0x1D,0x0B,0x29,0xAD,0x55,0x8F,0xB0,0xA3,0x34,0x99,0x87,0x39,0x26,0x74,0xD0,0x74,0x58,0x67,0x9B,0xC8,0x49,0x73,0xAE,0x4D,0x7D,0x43,0x37,0x2D,0x49,0x77,0xB7,0x89,0xD2,0x8C,0x2E,0xD1,0xB3,0x3A,0x56,0x33,0x87,0x46,0xA9,0x2D,0xD9,0xC5,0xEA,0x02,0xAD,0xD7,0x65,0x25,0xAB,0x0B,0xD4,0x3E,0x73,0x94,0xEC,0x26,0xD1,0xE3,0xC2,0x96,0x72,0x13,0x23,0xCF,0x4E,0x47,0xC2,0x0A,0xCC,0x2C,0x3B,0x6D,0x17,0x23,0x29,0x8B,0x38,0xB3,0xBD,0xB4,0x6C,0x3D,0x6A,0xC5,0xD1,0x51,0x8A,0x8B,0xC8,0x11,0x3B,0x47,0x2A,0x31,0x33,0x5B,0x9C,0x1C,0x3E,0xA7,0xAA,0x68,0x71,0x7A,0xB8,0x9C,0x3B,0xA3,0x35,0xC9,0x61,0x4B,0xAA,0x88,0xD1,0x38,0x8B,0xCD,0xB1,0x22,0x86,0xED,0x0C,0x36,0xC5,0xF0,0x1C,0x72,0x1A,0xB8,0xE4,0xDD,0x7C,0x25,0x2A,0x93,0xBC,0xF0,0x88,0x2A,0x5B,0x81,0x8D,0x3E,0xCC,0x57,0x6D,0x0F,0x36,0xC6,0xF4,0x58,0x73,0xB2,0xB8,0x18,0xCB,0x6C,0x43,0xC9,0xE0,0x53,0x6C,0x97,0x0D,0x25,0x4D,0x88,0xA5,0x4D,0x26,0x14,0x17,0x31,0xD4,0x52,0xDD,0x50,0x52,0xA4,0x50,0x5B,0x79,0xC2,0x71,0x93,0x43,0x4D,0xB1,0x0D,0xD9,0x4D,0x8E,0xCD,0x45,0xDF,0x15,0x37,0x39,0x76,0x13,0x3F,0x57,0x3C,0x94,0x58,0x53,0xE5,0x42,0xF1,0x50,0x63,0x29,0xE5,0x4D,0xC5,0x4D,0x8B,0xAD,0x44,0xAE,0x98,0x34,0x33,0xD6,0x12,0xBD,0x46,0x5A,0x9C,0xD8,0x93,0x75,0x87,0x6E,0xF1,0x62,0x2B,0xA1,0x1D,0x7A,0xC9,0x0F,0x3D,0x85,0x77,0x90,0x85,0x20,0x4C,0x67,0xBD,0x44,0xE2,0xA2,0xB0,0x95,0xFD,0x0A,0xB1,0x89,0xFD,0x74,0xF2,0x29,0xC4,0x2A,0x8E,0xC7,0x49,0x2A,0x15,0xC3,0x03};
const uint8_t rojo[] PROGMEM = {0x4D,0x8C,0x49,0x2A,0xC7,0xAB,0x0C,0x31,0x64,0xCD,0x9C,0x88,0xBB,0xC4,0x18,0x32,0xAC,0xD3,0xEE,0x11,0x93,0xAF,0x94,0x6A,0x39,0x4B,0x8E,0xA9,0x4C,0xA6,0x65,0x0F,0x25,0x96,0x12,0x99,0x96,0x33,0xB4,0x58,0x4B,0x64,0x5B,0x71,0x33,0x62,0x69,0xA5,0x6D,0xBA,0xCD,0x0A,0xAD,0x44,0xAE,0x91,0x26,0x27,0xB4,0x10,0xB9,0x42,0xEC,0xDC,0x50,0x5D,0x68,0x4B,0x91,0xF1,0x73,0x38,0x51,0x15,0xD9,0xCA,0x2B,0xE1,0x33,0x33,0x1C,0xAB,0xA3,0xA6,0x8F,0x4A,0x4F,0x64,0xEC,0xEA,0x3F,0x32,0x3D,0xB1,0xB1,0x4B,0x7A,0x2B,0xCB,0x44,0xCE,0x73,0xB1,0x54,0x7D,0x64,0x27,0xCF,0x97,0x32,0xEE,0x95,0x5C,0x7C,0x9F,0xDA,0xA8,0xCE,0x4A,0x0A,0x42,0x2E,0xE5,0x3A,0x31,0x21,0x0A,0x23,0x44,0x76,0xA8,0xB8,0xD8,0xF7,0x60,0x99,0xA1,0x6A,0x12,0x5F,0x93,0xB4,0x8A,0x8E,0x4A,0xBC,0x1A,0x65,0x75,0xC7,0x24,0xAE,0xA2,0xCC,0x45,0xA5,0x3C};
const uint8_t verde[] PROGMEM = {0x4C,0x85,0xA9,0xBD,0xAB,0x22,0x09,0x15,0xE6,0x8E,0xCA,0x8A,0x1C,0xE4,0xA0,0x2D,0xA2,0x43,0xCA,0x12,0x93,0xB1,0xAC,0x0D,0xC7,0x4B,0xAC,0x46,0xA3,0xCE,0x9C,0x1E,0xB1,0x69,0x8D,0x1A,0xB3,0x73,0xE4,0x66,0x24,0x6A,0x4D,0xF6,0x51,0x9B,0xD6,0xA8,0x75,0xDB,0xC7,0x68,0x5A,0x23,0xD7,0x1D,0x0F,0xB3,0x6A,0x75,0x3F,0x77,0x1C,0xDC,0x64,0xD5,0x7D,0x43,0x76,0x72,0xA3,0xD3,0xF0,0x75,0xC5,0xCE,0x4B,0x56,0x43,0x4F,0x6D,0x0B,0xDF,0x4B,0x33,0x8F,0x96,0xED,0xFC,0xA4,0x34,0x7C,0x52,0x71,0xF1,0xB3,0xD0,0x8E,0x53,0xD9,0x25,0x28,0x42,0xBA,0x4E,0x6C,0xA7,0xB0,0x08,0xEE,0x3E,0x95,0x1D,0xA2,0xCA,0xA9,0x67,0x85,0xB6,0x8B,0x2B,0xC7,0x9A,0x11,0x3A,0x2A,0x1E,0x12,0x22,0x5B,0xE9,0xC0,0x03};
const uint8_t blanco[] PROGMEM = {0x4C,0x05,0xCB,0x63,0x2A,0xCD,0x08,0x15,0x94,0xC9,0x9C,0x8C,0x5D,0x64,0x6F,0xD4,0x73,0x42,0x4A,0x13,0x23,0x0F,0x8F,0x09,0x29,0x4D,0x4C,0x34,0xD3,0x3B,0xC4,0x0E,0x21,0xB1,0xCC,0x98,0x24,0x3B,0xC4,0x24,0xD3,0x73,0x92,0xCA,0x11,0xB3,0x89,0x9C,0x61,0xD5,0x47,0x2C,0x36,0x63,0x46,0xD5,0x1C,0xA9,0xF8,0x88,0x6A,0x71,0x7C,0xE4,0xEA,0x22,0xBC,0x55,0xF1,0x51,0x9A,0x0B,0xB7,0x36,0xDB,0x47,0xEB,0xD6,0xDD,0x46,0x65,0x1F,0xA3,0x6B,0x73,0x2D,0x97,0x3D,0xAC,0xCA,0x35,0x34,0x55,0x49,0x70,0x94,0x0D,0xD7,0xD2,0x5A,0xCE,0xE1,0x3E,0x4C,0x5B,0xA6,0x18,0x87,0xC6,0x70,0x2D,0x1D,0xCD,0x5C,0xD0,0xD2,0xB5,0x35,0x22,0xF2,0x98,0x6E,0x6B,0xB7,0xC4,0x10,0xFE,0xB2,0xDA,0x2A,0xDC,0x76,0xF2,0x42,0x0A,0xB5,0x2A,0x39,0xCD,0x0F,0x29,0x8D,0x7B,0x25,0xB7,0x20,0xE4,0x34,0xEA,0xB3,0x54,0xC2,0xD0,0x42,0x65,0x96,0x6A,0x8A,0x42,0x4D,0xA3,0x1D,0x24,0x21,0x0E,0xDD,0x85,0xB7,0xE0,0x99,0xC4,0xB7,0x20,0xE9,0x64,0xA6,0xD2,0x60,0x07,0xA1,0x83,0x19,0x4B,0x93,0x5E,0x81,0x52,0x26,0xF0};
const uint8_t errorAlTomarMedida[] PROGMEM = {0x45,0x6D,0x8A,0xA3,0xD6,0x14,0x37,0xAD,0x29,0x8E,0x5C,0x97,0x3D,0x8C,0xA6,0x24,0x62,0x5D,0x71,0x33,0xAB,0xD2,0xF0,0x75,0xC7,0xC1,0x2A,0x5A,0x5D,0x37,0x6D,0x07,0x2B,0x3B,0x55,0xEB,0xB2,0x13,0x8C,0xCA,0xC2,0x3D,0xAB,0x76,0xD0,0x92,0x57,0xB3,0x6E,0xDB,0x45,0x89,0x41,0xC3,0x36,0xA2,0x36,0x39,0x06,0x0F,0x9D,0xB4,0x3A,0xC4,0x14,0xCB,0xA5,0xDB,0xCE,0xE0,0x52,0x6A,0x97,0x6A,0xBB,0x83,0x4D,0x39,0xDC,0x26,0xEC,0x35,0x26,0x65,0x29,0x9F,0xB0,0xEA,0xE8,0x14,0xB9,0xA2,0x2C,0xCC,0xA0,0x93,0x8B,0xCC,0x91,0xB8,0x8B,0x29,0x2E,0xCB,0x87,0xED,0x2E,0xAE,0xB8,0xA8,0x1C,0xB1,0xB2,0xA4,0x62,0x3D,0x63,0xC5,0x6A,0x53,0x92,0xF6,0x88,0x13,0x3B,0x41,0x8B,0xD2,0x3D,0xCE,0xE9,0x28,0x33,0x52,0x53,0xDF,0x92,0x0A,0x10,0xB4,0x22,0xDD,0x3C,0x32,0xF1,0x30,0x92,0x09,0x97,0x69,0x25,0xC3,0x4A,0xAE,0x4C,0x7A,0x64,0x37,0x3B,0xFA,0x36,0xCA,0x95,0x1A,0x1C,0xEF,0x92,0x39,0xCB,0xA9,0xB3,0x75,0x30,0x8A,0xC8,0xA4,0xC1,0x54,0x41,0x25,0xA2,0x92,0x34,0x2D,0x25,0x67,0x2B,0x57,0x7C,0xD4,0x92,0x53,0x6D,0x5C,0xF1,0x51,0x6A,0x4C,0xB7,0x71,0xD9,0x47,0xAE,0x21,0xC2,0xC7,0x14,0x1F,0xA5,0xBA,0x08,0x1B,0xB3,0x53,0x94,0x6C,0xCC,0x6D,0xCD,0x76,0x51,0xA3,0x93,0xC8,0xD5,0x28,0x4E,0xE5,0xC1,0xA2,0xD2,0x63,0x07,0x95,0x46,0xF7,0x8E,0x88,0x13,0x54,0xE6,0xD2,0x23,0x33,0xC9,0xD2,0xAA,0x94,0xF0,0x76,0xD9,0xC7,0x18,0x8A,0xDD,0xC7,0x65,0x1F,0x73,0x68,0x36,0x3F,0x57,0x3C,0xEC,0xAE,0xD8,0x6C,0x52,0xB6,0x71,0x23,0x13,0xF7,0x2A,0xDB,0xC9,0x6A,0x1C,0x23,0xCE,0x6D,0x35,0x63,0x08,0xD4,0x3A,0x97,0xD5,0x8C,0xC1,0x50,0xFA,0xCC,0x56,0x33,0x27,0x47,0x9E,0x57,0xC9,0xC5,0x1A,0x84,0x6C,0x4F,0xC8,0x16,0xA7,0x0B,0xD4,0x79,0x17,0x5D,0xDC,0xC6,0x29,0x72,0xDD,0xB1,0x09,0x32,0xE3,0xD4,0xB1,0x58,0xC9,0x8F,0xCA,0x2A,0x96,0x6D,0xB7,0x20,0x6B,0xCB,0x18,0xB2,0xD3,0xC2,0xE2,0x2C,0x7C,0xD0,0x4A,0x09,0x8B,0xB7,0xF0,0x24,0x2B,0x25,0x1A,0x2E,0x8C,0x5D,0x25,0x97,0x78,0xC6,0x0E,0xB5,0xB0,0xEC,0x92,0x19,0x26,0x25,0x2B,0xA9,0xC8,0x87,0x1B,0xE7,0x89,0x34,0xF0};
const uint8_t modoAhorroActivado [] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x54,0x98,0xC6,0x33,0x33,0xB6,0x51,0x49,0x0A,0xAD,0xAC,0x26,0x4E,0xA1,0xA1,0x34,0xAA,0xD2,0x24,0xD9,0xF8,0x11,0xA9,0x70,0xDC,0xC4,0x18,0x8F,0x79,0x5A,0x76,0xE3,0x53,0x38,0xA1,0x6D,0x39,0x8D,0x4D,0xE9,0x58,0xB6,0xA9,0x0E,0x36,0xD5,0x61,0xBE,0xA6,0xDD,0xD8,0x98,0x9B,0xE5,0xDD,0xB6,0x63,0x53,0x49,0x96,0x75,0x3B,0x8A,0x0E,0xA2,0x5C,0x33,0x63,0x17,0x2A,0xC6,0x14,0x5D,0x93,0x3D,0xE8,0x18,0x4B,0x74,0x42,0xD6,0x60,0x62,0x6C,0xE3,0x6D,0x4B,0x8D,0x8B,0xAD,0x44,0xAF,0xE4,0x0C,0x31,0x96,0x56,0xDD,0xA4,0xB3,0x94,0x54,0xD2,0xF4,0x5C,0xC9,0x32,0x72,0x4E,0xD3,0x0D,0x39,0xCB,0x2A,0xA9,0x5C,0xD6,0x65,0x2F,0xA7,0x94,0x74,0xDB,0x90,0xBD,0x9C,0x5C,0xD2,0x75,0x43,0xF1,0x70,0x72,0x2D,0xE3,0x29,0xC6,0xCD,0x49,0xB9,0x55,0xA6,0x65,0x17,0x33,0xE6,0x56,0xDA,0xA1,0x53,0xB4,0x58,0x5B,0x68,0x87,0x6A,0x51,0x42,0x5E,0xA5,0x19,0xBA,0x45,0x0A,0x6D,0x98,0x77,0xE4,0x34,0x31,0x8E,0x12,0x99,0xB1,0xD2,0xC4,0x50,0xC2,0x65,0xD2,0x4E,0x92,0x42,0xE1,0xF2,0x76,0x3B,0x49,0x0A,0x49,0xB2,0x2A,0x43,0x07,0x29,0x46,0x8D,0x1C,0x8F,0x5C,0xE4,0x90,0xA5,0x62,0xA2,0x4C,0x53,0x42,0xB6,0x88,0x8E,0xA8,0x43,0x8D,0x21,0x5D,0xBA,0xAC,0x2C,0x2D,0xA5,0x34,0x9D,0x96,0xB3,0xCC,0x1C,0xC3,0x6D,0x5A,0xC9,0xB2,0x8B,0x0F,0xB7,0x2E,0xD9,0xCD,0x29,0x46,0x43,0xA7,0x64,0x0B,0xBF,0x29,0x4E,0xF5,0x74,0x64,0xC6,0x51,0x22,0x33,0xDD,0x0E,0x7B,0x46,0x4D,0x73,0x71,0xD9,0x28,0x9C,0xC1,0xD8,0x8D,0x65,0xA1,0x63,0xDA,0xF2,0x30,0x95,0xED,0x8C,0x2A,0xD9,0xCD,0x35,0x4D,0x32,0xBB,0x40,0xCB,0x33,0x5B,0xC5,0xEA,0x02,0xAD,0x36,0x6C,0x16,0xBB,0x4B,0xD4,0x9E,0xB4,0xED,0x9C,0xC2,0x38,0xC2,0xCB,0xB1,0x72,0xA3,0x70,0x53,0xAD,0x38,0xC5,0x4C,0xDE,0xDC,0x26,0xE5,0x2C,0x33,0x7B,0x0F,0xDF,0x90,0x7D,0xCC,0x12,0x23,0x7C,0x42,0xF1,0xB1,0x4A,0xCC,0xB4,0x31,0xD9,0xC7,0x2E,0x29,0x22,0xD6,0x64,0x2F,0xB7,0xC4,0x0C,0x5B,0xB5,0x3D,0xBC,0x12,0x22,0x7C,0xC5,0x72,0xF1,0x73,0x70,0xF7,0xA3,0xB0,0x26,0x48,0xC6,0x5C,0xDB,0x2D,0xA9,0x20,0x58,0x37,0x9B,0x60,0x1C,0xC2,0xE0,0x3D,0x74,0x95,0x95,0x8B,0x42,0x74,0xD7,0x71,0x46,0x26,0x0E,0x39,0x84,0xAB,0x24,0xAB,0x24,0xEB,0x31,0x94,0x90,0xC2,0xB2,0x62,0x2E,0xB4,0x22,0x11,0x4A,0xBA,0xAC,0xCC,0xB2,0x24,0x68,0x1F,0xBA,0xA2,0x32,0x6C,0xA3,0x71,0x98,0xF6,0x0A,0x77,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0};
const uint8_t modoAhorroDesactivado [] PROGMEM = {0x46,0xC5,0xB9,0xAC,0xB2,0x92,0x18,0x85,0xA4,0x90,0xCE,0x6C,0x1A,0x64,0x1E,0x5A,0xBC,0x32,0x4E,0x13,0x43,0x38,0xE6,0x2E,0xDB,0x4D,0x48,0xE1,0x84,0x66,0xE4,0x0C,0x2E,0xE5,0x63,0xDE,0x96,0x3C,0xB8,0xD4,0x86,0x74,0x5B,0x4A,0xE3,0x62,0x1E,0x91,0x2B,0xC5,0x81,0x4B,0xB1,0x85,0x36,0xE5,0x28,0x3A,0xA8,0x32,0xCD,0xB2,0x5D,0xE8,0x18,0x52,0x75,0xD5,0x4E,0xA3,0x63,0x28,0x95,0x0D,0xCB,0x8D,0x89,0xB1,0x8D,0xB7,0x25,0x37,0x3E,0xB6,0x12,0xDD,0x52,0x32,0xC4,0x54,0xCA,0x6C,0x43,0xF1,0x52,0x72,0x49,0xB3,0x75,0xC7,0xCB,0x28,0x25,0xCD,0xD6,0x15,0x1F,0xAB,0xE4,0x0C,0x5D,0x53,0xBC,0xEC,0x92,0xCB,0x75,0x83,0xF1,0x70,0x72,0x2E,0x97,0x49,0xC6,0xC3,0xC9,0x3D,0x45,0xA6,0xE4,0x34,0x27,0xE5,0x56,0x9E,0x66,0x5A,0xAC,0x58,0x4B,0x64,0x87,0x6E,0x31,0x62,0x19,0xE6,0x59,0xAA,0x45,0x0D,0x61,0x95,0x66,0xA8,0x15,0x39,0xC4,0x35,0x9C,0xA1,0xD7,0xC4,0xD8,0x5B,0x78,0xC7,0x76,0x13,0x42,0x4B,0x93,0x29,0x3B,0x45,0x88,0x55,0xCA,0x27,0xEC,0x04,0x21,0x46,0x09,0x1F,0x2D,0xED,0xF8,0xE8,0x2C,0xAC,0xC3,0x52,0xE1,0x63,0xD6,0xF0,0x89,0xC8,0x8D,0x8F,0xD9,0xDC,0x2F,0xE2,0x0C,0x21,0xC6,0x72,0xDD,0x70,0xD2,0xA4,0xE0,0xCB,0xF5,0xDC,0x49,0x92,0x83,0x4B,0xD3,0x4B,0x47,0x42,0x73,0xD2,0xDD,0xBA,0x1C,0x17,0x2D,0x1A,0x8F,0xB8,0x70,0x3C,0x8C,0xA2,0xD4,0xFD,0xC2,0xF1,0x30,0xAB,0x12,0xB7,0x0B,0xC7,0xC5,0xAE,0x52,0xDC,0xCE,0x6C,0x1B,0xB7,0x6A,0x36,0x59,0xB5,0xCD,0xBA,0xD6,0x43,0x3A,0x55,0xB2,0xF8,0x5B,0xB7,0x6C,0x57,0xC5,0xC1,0x48,0xD6,0xC3,0x46,0x62,0x0F,0x2B,0x3B,0x4B,0x5B,0x89,0xB2,0x9C,0xE6,0x34,0x6D,0xDC,0x4E,0x71,0x9B,0xA5,0x88,0x4E,0xDB,0x22,0xEA,0x5A,0xC5,0xC3,0x1D,0xAB,0x7F,0xE4,0xCC,0x0C,0xB3,0x4D,0xFE,0x19,0x43,0xC4,0x54,0x36,0xC2,0x47,0x48,0x56,0x33,0x89,0xE8,0xEE,0x2E,0x22,0xC2,0x14,0x3B,0xB3,0x4A,0x72,0x4F,0x75,0x93,0xAC,0x2E,0xD0,0xEA,0x42,0x56,0xB1,0x87,0x42,0xAD,0x0D,0x47,0xC5,0x69,0x12,0xAD,0xA7,0x6C,0x19,0x37,0x32,0xF5,0xF0,0x4C,0x6C,0xEC,0x24,0x5D,0xCC,0x32,0x4E,0x33,0x73,0x30,0xF7,0x29,0x39,0xC7,0x2C,0xC1,0xC3,0xD6,0x15,0x1F,0xB3,0xA4,0x08,0x5B,0xB3,0x73,0xAC,0x92,0x32,0x7D,0x55,0xF6,0x72,0x4A,0x8E,0x88,0x55,0x5B,0xC3,0x2D,0x29,0xC2,0x57,0xC2,0x36,0x3F,0x07,0x0F,0x3B,0x8E,0xEA,0xC2,0xEC,0xCD,0x75,0x5D,0x96,0x08,0x93,0x76,0xB1,0x2C,0xDB,0x21,0x8C,0x41,0x2D,0x56,0x19,0xBB,0x28,0x06,0x77,0x59,0xA3,0x6D,0xA2,0x18,0xC3,0xB0,0x8B,0xB2,0x8A,0x93,0x69,0x41,0x0F,0x2B,0x2C,0x6B,0x62,0x4B,0xD2,0x24,0xA1,0xB3,0xC9,0xA9,0x0C,0x4B,0xF2};
const uint8_t conexionCargador [] PROGMEM = {0x4C,0xE9,0x31,0x39,0x42,0x6D,0xA1,0xA0,0xC7,0x51,0xCF,0xB0,0x88,0x80,0x11,0xD7,0x58,0xD2,0x47,0x78,0xB5,0x5B,0x34,0x52,0xB3,0xA2,0x32,0xAA,0xA8,0x69,0x49,0x58,0xD5,0xA9,0xAD,0xA1,0x15,0x29,0x51,0x6F,0x8E,0x97,0xD6,0x94,0x78,0xAE,0xD9,0x3E,0x5A,0xD5,0x9A,0xB5,0x6A,0xFB,0x68,0xD5,0x58,0xE6,0x98,0x9D,0xA3,0x55,0x67,0x99,0xE3,0x72,0x8E,0xD6,0xAC,0xA6,0x8F,0x2B,0x29,0x5A,0xD3,0x92,0x5E,0x29,0x87,0x38,0xC3,0xA6,0x79,0x98,0x6D,0x44,0x75,0xDB,0x1E,0x6A,0x8E,0x9C,0x98,0x5F,0x59,0x86,0x5A,0x29,0x6A,0xF0,0xED,0x1A,0x1B,0x65,0xA8,0xD1,0x95,0x6B,0x4C,0x94,0xA5,0xE5,0xE0,0xA6,0x55,0x51,0x9A,0x99,0xBD,0x8A,0x8E,0x5B,0x71,0xA6,0xB2,0xE6,0xB1,0x12,0x3B,0x98,0x56,0x7A,0x7A,0xA9,0xEB,0x61,0x75,0x2D,0x66,0xEB,0xB2,0x87,0x33,0x2C,0xAB,0x4F,0xC8,0x2E,0xCE,0xB0,0x68,0xD9,0x29,0x5B,0x05,0xD3,0x92,0x78,0x84,0x6D,0xB3,0x8D,0x1C,0x19,0x6E,0x4E,0xC4,0x3E,0x72,0xB8,0x9B,0xCA,0x46,0xC0,0xB2,0x6E,0x20,0xB2,0xE6,0x22,0xD4,0xCD,0x71,0x53,0x92,0xB3,0xC8,0xA5,0x38,0x47,0x2E,0x3E,0x22,0x97,0xE3,0x1C,0x29,0xC7,0xCA,0x18,0x71,0x72,0x84,0x9C,0x2B,0x63,0x24,0xC9,0xE1,0x73,0xCA,0xC8,0xD5,0x38,0x8D,0xCB,0x3E,0xC3,0x56,0xEC,0x2A,0x36,0x29,0x37,0xAD,0xB0,0x5D,0xE8,0xE4,0xC3,0xFC,0x59,0xCE,0xA0,0xA3,0x2F,0xB7,0x53,0x39,0x83,0x89,0xA1,0xDD,0x36,0x94,0x2C,0x36,0xF9,0x74,0xBF,0x54,0xBC,0x84,0x6C,0x3C,0x63,0x5D,0xC9,0x92,0xAB,0xD4,0xCC,0x09,0x25,0x47,0x6D,0x4A,0x3C,0x37,0x1C,0x0F,0xA3,0x0A,0xF5,0xDC,0x72,0x5C,0xAC,0x42,0xB5,0x32,0xA7,0x54,0xB2,0x13,0xD3,0xEA,0xAC,0xD0,0xC2,0x2D,0x4C,0x2C,0x23,0x23,0x23,0x60,0x59,0x57,0x55,0x8F,0x94,0x95,0x61,0x76,0x8A,0xD1,0x94,0x44,0x64,0x24,0x5E,0x66,0xD5,0x5A,0x31,0x6E,0xFB,0xD8,0xD5,0x59,0xFA,0x84,0xED,0xE5,0x54,0x67,0x61,0xEB,0x8E,0x8B,0x5B,0xAC,0xB9,0x4C,0xD9,0x6E,0x6E,0xD1,0x92,0x76,0x1A,0x25,0x78,0x55,0x51,0xF9,0xB8,0x6C,0xE3,0x54,0xC1,0x9E,0x15,0x96,0x87,0x5B,0x95,0x54,0x76,0xC8,0x5E,0x5E,0x35,0x96,0xD1,0x21,0x67,0x79,0xD5,0x79,0xDA,0x9A,0xEC,0xE1,0x17,0x1F,0x61,0x6B,0xB2,0x8B,0x9F,0x5C,0xB8,0xAD,0xCB,0x56,0x41,0xE0,0x6E,0x16,0x65,0x3B,0x59,0xC9,0xBB,0xCA,0xA5,0xEC,0x61,0x24,0x1F,0xAA,0x5B,0xB2,0x97,0x9A,0x5C,0x9B,0x74,0xCB,0x5E,0x72,0xF2,0xED,0x92,0x63,0x65,0x49,0x29,0x87,0x6B,0x65,0x94,0x26,0xA5,0x2C,0x91,0xE5,0x61,0x83,0x14,0x82,0x85,0xAF,0xC9,0x0E,0x52,0x08,0x16,0x71,0x62,0xD9,0x28,0x41,0x9B,0xE9,0xA6,0x9D,0x22,0x47,0xEB,0x11,0x6F,0xB6,0x87,0x9C,0xB5,0x79,0xBE,0x39,0x5E,0x4A,0x55,0x1A,0x7E,0xEE,0x68,0xA8,0x45,0x9A,0xDB,0xA6,0xE2,0xA2,0x65,0xE6,0xE1,0xB3,0x41,0x86,0x91,0xB5,0x47,0xAC,0x2B,0x39,0x66,0x75,0xEE,0x7E,0x6E,0xFB,0xD8,0xC5,0x47,0xE8,0x85,0xE2,0xE1,0xE4,0x18,0xAE,0x93,0x8A,0x9C,0x9B,0xB4,0x2B,0x6B,0xC5,0x69,0x4E,0x4E,0x6E,0x3A,0xA5,0x64,0x39,0x25,0x86,0xDB,0xA6,0xE2,0xE5,0x16,0x1F,0x61,0xEB,0x8E,0x9B,0x5B,0xAC,0xB9,0x9D,0xDA,0x11,0x41,0x91,0xEA,0xD2,0x61,0x0B,0xB9,0x43,0x85,0xBA,0xB9,0x13,0x04,0x4E,0x13,0x11,0x6C,0x76,0x82,0x91,0xA5,0x46,0x94,0xBB,0x19,0x56,0x95,0x12,0x79,0x66,0x7B,0x38,0x5D,0xB1,0xC7,0x99,0xED,0xE1,0x74,0xC5,0x1E,0xE7,0xB6,0x93,0xD3,0x04,0xBB,0x6D,0x58,0x0E,0x56,0xE1,0x9C,0x75,0x6E,0xAB,0x58,0x5D,0xA0,0xF7,0x9B,0xA5,0x62,0x0E,0x8E,0xD2,0x67,0x96,0x92,0x35,0x09,0xE9,0x9C,0x4A,0x4E,0xF6,0xA4,0x24,0xF3,0x4A,0x36,0xB8,0x83,0x90,0xDD,0x3B,0xA1,0xE0,0x17,0x2C,0xF5,0x27,0x52,0x52,0x90,0xB9,0xD6,0x0E,0x59,0x4E,0x61,0x56,0xDA,0x99,0x64,0x27,0xC5,0x4D,0x69,0x58,0xAA,0xE5,0x92,0x8C,0x54,0xA1,0xE1,0xB6,0x53,0x3C,0x63,0xA5,0x56,0x26,0x75,0xC0,0x0C,0x5D,0xEA,0x1A,0xAE,0x43,0x2B,0x9A,0xA2,0x7B,0xD8,0x76,0x9D,0x48,0xFC};
const uint8_t desconexionCargador [] PROGMEM = {0x44,0xED,0x3E,0x25,0xCD,0x1C,0xA1,0xB3,0xA7,0x55,0x73,0xB7,0x88,0x80,0xE9,0xD7,0x10,0xD2,0x4B,0xD9,0xF4,0xC4,0x22,0x50,0x5F,0xA5,0xE9,0x11,0x4B,0x71,0xBD,0x94,0xF3,0xA8,0xE4,0xA4,0x45,0x61,0x95,0xA7,0xB6,0x87,0x51,0x84,0x64,0xBE,0xD9,0x5E,0x46,0x53,0xEC,0x79,0xE6,0x78,0x19,0x5D,0x93,0xD7,0xB9,0xE3,0xA5,0x75,0xCD,0x5E,0xE3,0xB6,0x8F,0xD6,0x94,0x66,0x8D,0xD9,0x3E,0x5A,0xD5,0x5E,0x39,0x6A,0xFB,0x68,0xD5,0x7A,0xC4,0xAA,0xED,0x63,0x54,0x17,0x11,0x6B,0xB6,0x97,0x51,0x6C,0x84,0xAF,0xD9,0x0E,0x66,0xB1,0xA6,0x5A,0x29,0x4B,0x99,0x51,0xAA,0x59,0x95,0xED,0xA2,0x65,0xA5,0xE1,0xEF,0x8E,0x87,0x56,0x85,0x44,0xBC,0x27,0x5E,0x46,0x53,0x6C,0xFE,0xE1,0x78,0x98,0x55,0x89,0xFB,0xA5,0xE3,0x64,0x26,0xAD,0x91,0x6B,0x8E,0x95,0xDD,0x8C,0x29,0x8C,0xCB,0x21,0x6B,0xAB,0xE3,0x16,0xA6,0x98,0x00,0x75,0x45,0x13,0xA0,0xB5,0x4A,0xD4,0x0D,0xD7,0x9E,0x6D,0x92,0x40,0x1D,0xF9,0xB6,0x75,0xB8,0x9D,0xA0,0x85,0x90,0xA6,0xBD,0x76,0x9A,0x16,0x6D,0x85,0xF8,0xDA,0x1D,0x46,0xF2,0x65,0x92,0x6B,0x76,0x98,0x39,0xB8,0x49,0x97,0xD5,0x62,0x66,0x2F,0xA2,0xE3,0x51,0x9C,0x29,0xAC,0x47,0xB4,0xC4,0x0A,0xA6,0x51,0x9E,0x59,0xEA,0x78,0x98,0x5D,0x89,0xE9,0x9A,0xEC,0x65,0x0D,0x23,0x6A,0xEB,0xB2,0x87,0x3D,0x2C,0x5B,0x4C,0xD2,0x6E,0xCE,0xF4,0xA8,0x31,0x25,0xDB,0x78,0xD3,0x23,0x67,0x86,0x1D,0x05,0xCC,0x12,0x61,0x80,0x95,0x2B,0x59,0x34,0xF2,0x84,0x87,0xCB,0x46,0xC0,0xF2,0xAE,0x00,0x41,0xCE,0xC6,0x3C,0xCB,0x6D,0x0F,0x39,0x7B,0x8B,0x5A,0x8E,0x7D,0xE4,0x12,0x22,0x73,0x38,0xEE,0x91,0x72,0xCA,0xCC,0x16,0x3B,0x47,0xC8,0xA9,0x33,0x5A,0x92,0x2C,0x2E,0xA7,0x8C,0x1C,0x8D,0xDD,0xB8,0xEC,0x2A,0x6D,0xD9,0x8E,0xE1,0xB3,0x0D,0xD3,0x76,0xC7,0x8A,0x8E,0x26,0xCC,0x26,0x64,0x37,0x3A,0xFA,0xB4,0x58,0x95,0x3B,0xE8,0x18,0xCA,0x6D,0x5C,0xCE,0x60,0xA2,0x6F,0xB7,0x4D,0x25,0x8B,0x4B,0x3E,0xDD,0x27,0x9D,0x2C,0xA1,0x68,0x8F,0xD8,0x50,0xB2,0xA4,0xAA,0x35,0x6A,0x42,0xC9,0x52,0x9B,0x12,0xCF,0x0D,0x3B,0xC3,0x68,0x4A,0x2C,0x2E,0x1C,0x17,0x2B,0x13,0xAB,0xEA,0x0E,0x1D,0xEC,0x42,0xB4,0x3A,0xA3,0x52,0x70,0x32,0x95,0xDE,0x8C,0x48,0xC4,0xCB,0x44,0x34,0x33,0xE2,0x00,0x98,0x69,0x54,0xAF,0x4C,0xB3,0x53,0x8C,0x22,0x35,0x2B,0xDD,0xF6,0x32,0x8A,0xB1,0xF2,0x76,0xDB,0xC7,0xAC,0xDE,0xD2,0x27,0x6C,0x2F,0xAB,0x3A,0x0F,0x5B,0xB7,0x5D,0xEC,0x6A,0xCD,0x79,0xDD,0x4A,0x73,0x8A,0x96,0xB0,0x73,0xDB,0xC9,0xAD,0x8A,0xCB,0x56,0xE3,0x18,0xAF,0x4A,0xAC,0x28,0xB3,0xED,0xEC,0xA6,0xC8,0x2A,0xD3,0x4E,0x73,0xAA,0x92,0x8E,0x0E,0xD9,0xCB,0xAD,0xC6,0xD2,0x3B,0x94,0x2C,0xAF,0xD8,0x48,0x9F,0x90,0x3D,0xBC,0xE2,0x22,0xED,0xD4,0x76,0xF3,0xB3,0x8B,0xD0,0x13,0xDB,0xC9,0xCF,0xD6,0x5D,0xCE,0xEC,0x08,0xDF,0x72,0x77,0xCF,0xB2,0xE5,0xDC,0x64,0xC3,0x74,0x53,0x4E,0xB3,0xA3,0x0F,0xB3,0x4B,0xD9,0xC3,0x48,0xAE,0x5C,0x66,0xE8,0x0E,0x35,0xF9,0x36,0xE9,0x91,0xBA,0xE4,0x14,0xC6,0xA4,0xC6,0xF2,0x12,0x53,0x2E,0xD3,0x6A,0x33,0x83,0x4F,0xD9,0xC2,0x3B,0xE2,0x06,0x21,0x45,0x8E,0x6C,0x8F,0x92,0xC4,0x10,0x2D,0xF3,0xC4,0xB2,0x91,0xBD,0x75,0xB7,0x0D,0x9A,0x4C,0x25,0x76,0xB2,0x2A,0x6C,0x1B,0xC5,0x6B,0xF3,0x18,0x97,0xD5,0xE4,0x68,0x3C,0xEB,0xD5,0xF6,0x52,0x8A,0xD4,0x88,0x57,0xDB,0x4B,0x6D,0x46,0x2C,0xCE,0x15,0x37,0xAD,0x28,0xB5,0xD8,0x94,0x5D,0xB4,0x4C,0xBC,0xA2,0x26,0x70,0x31,0x22,0xAB,0xCA,0xEE,0x30,0xCB,0x28,0xC6,0xC3,0xCF,0x6C,0x1F,0xAB,0xBA,0x08,0x3B,0xB3,0x7D,0xEC,0x12,0x22,0xEC,0x42,0xF1,0x70,0x72,0x8C,0xD0,0x4D,0xC5,0xCE,0x4B,0x36,0x44,0xB4,0xAC,0x38,0x3B,0xF9,0x60,0x8B,0xB2,0x32,0xEC,0x9C,0xDC,0x6D,0x53,0xF1,0x72,0x4A,0x0C,0xB7,0x0D,0xC5,0xCB,0xAD,0x2E,0x42,0xD7,0x1D,0x37,0xB7,0x38,0x73,0x5B,0xB3,0x1D,0xBC,0xA8,0x3C,0x7C,0xCD,0x16,0x09,0x9B,0x76,0x16,0x75,0xC7,0x28,0xEA,0x2A,0x2C,0xDC,0x6D,0x83,0x31,0xB2,0xD4,0xB0,0x51,0x27,0xCD,0x2E,0x52,0x32,0x4E,0x6D,0x0F,0xA7,0x29,0x89,0x5C,0xB7,0x3D,0x9C,0xA6,0x38,0x72,0x43,0x76,0x73,0xBB,0x62,0x8F,0x0B,0xD9,0xC1,0x6D,0x82,0xDD,0x36,0x64,0x3B,0xBB,0x30,0xAE,0x5A,0x97,0x54,0xCC,0x2E,0x30,0xFA,0xCD,0x56,0x31,0x06,0x47,0x9D,0x35,0x4B,0xC9,0x18,0x1C,0x79,0x4F,0x2D,0x27,0x73,0x52,0x92,0x39,0xB5,0x1D,0x80,0x49,0x49,0x82,0x3B,0x29,0xC9,0xBE,0x91,0x09,0x7E,0xC3,0x14,0x7F,0x66,0x39,0xF9,0x19,0x6B,0xEF,0xB0,0x9D,0x14,0x24,0xA1,0x33,0x4D,0x56,0x52,0x50,0x94,0x64,0x37,0x59,0x4E,0x61,0x56,0x51,0x9E,0xA2,0x38,0x45,0xDD,0x9A,0x6B,0x98,0xEC,0x14,0xCF,0x98,0x61,0x6E,0x96,0x43,0x34,0x62,0xA7,0x66,0xC4,0x31,0xC9,0xF4,0x1D,0x5A,0x99,0x86,0xBD,0xC3,0xB5,0xEB,0x64,0x1A,0x04,0x4C,0xDB,0xF6};
//G:\___Yo\cuisde\Audios\Numeros\Editados
const uint8_t un [] PROGMEM = {0x00,0xE0,0x78,0xDB,0x5A,0x78,0x42,0x71,0xE1,0x7C,0x19,0xC1,0x2A,0x25,0x85,0xF3,0x75,0x08,0xBB,0x1D,0x37,0xD6,0x97,0x21,0xAA,0x8A,0xDB,0x58,0x1F,0x5A,0x38,0xD3,0x6E,0x63,0x43,0x74,0xD1,0xCE,0x38,0x85,0xB3,0x41,0x2D,0xC6,0xE2,0x04,0x9E,0xA7,0x48,0x2F,0xAD,0x13,0x78,0x1E,0x32,0xB2,0x34,0x09,0x42,0x8D,0x09,0xCF,0x72,0xC7,0x0F};
const uint8_t dos [] PROGMEM = {0x00,0x49,0x0A,0xDE,0xA2,0xCE,0x65,0x0F,0x39,0x39,0xB3,0xB8,0x50,0xB2,0x94,0xE4,0xC3,0x6C,0x52,0xF1,0x52,0x53,0x28,0x93,0x2D,0xC5,0x43,0x4B,0xA9,0x54,0xB7,0xE5,0x34,0x23,0x95,0x12,0xD9,0xA1,0xDB,0xEC,0x58,0x4A,0x64,0x97,0x49,0x71,0x63,0x2E,0xE5,0x1D,0xA6,0xC9,0x8F,0x3D,0xD8,0xAE,0x90,0x85,0x20,0x0E,0x67,0xFD,0x44,0x6A,0xC2,0xB0,0xC8,0x7A,0x48,0xA3,0x8A,0x42,0x35,0xCD,0x94,0x14,0xCA,0xAE,0x3E,0x2C,0x42,0x5B,0xB1,0xA3,0x87,0xCA,0x68,0x8E,0x0C,0x0F};
const uint8_t tres [] PROGMEM = {0x00,0x4E,0x2C,0x46,0xDD,0xDB,0xA2,0x36,0x29,0x1A,0xAF,0x3C,0x8D,0x13,0xA4,0xA8,0x3D,0xE2,0x42,0xE6,0x90,0xB2,0xB2,0x8C,0xD7,0xC4,0x4B,0x6E,0x5A,0xBC,0xCE,0x9C,0x1C,0xA5,0x1B,0xF6,0x5C,0xB3,0x7D,0xB4,0xAE,0xD9,0x6B,0x5D,0xF6,0x32,0x86,0x66,0xAF,0x71,0xC7,0xCB,0x1A,0x9A,0xA2,0xD6,0x1C,0x37,0xB7,0x49,0xAA,0x19,0xB1,0x5D,0xFC,0x22,0xA4,0x7B,0xC8,0x71,0x08,0x92,0x90,0xA9,0x26,0xDB,0x2E,0x8A,0x52,0x27,0x1B,0xA3,0x98,0xA8,0x08,0x71,0x1D,0xB5,0x25,0xFC,0x61,0xC2,0x2C,0x9D,0x0A,0xEA,0x7B,0x4E,0xF5,0x12,0x45,0x0F};
const uint8_t cuatro [] PROGMEM = {0x00,0x44,0x34,0x6E,0x42,0xD5,0x93,0x38,0xC9,0xE4,0x33,0xD1,0x09,0x9D,0x44,0x57,0x56,0x35,0xD7,0x72,0x13,0x43,0x2D,0xD5,0x1E,0xA5,0x4B,0x4A,0x39,0x3D,0xA6,0x14,0x2F,0x39,0xE7,0x0C,0xDB,0x70,0x7C,0xD4,0x92,0x22,0x7C,0xCD,0xF6,0xD2,0x4A,0x8C,0xF0,0x75,0x39,0xCB,0x2E,0x3E,0xC2,0xD7,0xEC,0x34,0xB7,0x58,0x77,0x3B,0xB5,0x6D,0xFC,0xA2,0x42,0x6D,0x4A,0x36,0x02,0x7E,0x74,0x43,0xC0,0x6F,0xAD,0xC6,0xEC,0x26,0xCC,0x4D,0x9D,0x24,0x2F,0x5A,0x8F,0x9C,0x60,0xEC,0xFC,0xAC,0xCC,0x3C,0xC7,0x72,0x09,0x92,0x53,0x8F,0x2E,0xCB,0x29,0x8C,0xDE,0xC3,0xB2,0xAC,0x84,0x38,0xC6,0x34,0xCB,0x36,0xEB,0xE2,0x90,0xD2,0x24,0x96,0x8A,0x49,0x62,0x18,0x96,0x18,0xD1,0x22,0xCE,0x6A,0x89,0x35,0x1C,0xC3,0x03};
const uint8_t cinco [] PROGMEM = {0x80,0xC4,0x62,0x8C,0xAD,0xC3,0x09,0x11,0x5B,0x91,0x08,0x0D,0xC9,0x68,0x6C,0xCB,0x2D,0x2D,0x0D,0x02,0xAA,0xFA,0x3B,0x33,0x62,0x9B,0x44,0xEB,0xB7,0xD3,0x5A,0x5A,0x18,0xA1,0x8F,0x76,0x6D,0x57,0x54,0xF8,0xC2,0xD9,0xE3,0x42,0xCE,0x10,0x86,0x26,0x89,0x73,0xDB,0x0B,0x98,0x9A,0x64,0x88,0x53,0x91,0xF6,0x29,0x95,0x21,0x4D,0x4E,0xB6,0xCB,0x74,0x87,0x32,0x18,0xC6,0x35,0x29,0x19,0x6A,0x27,0x98,0x9B,0x94,0xA6,0x69,0x8D,0x60,0x8E,0x71,0xE7,0x64,0x5A,0x16,0x2D,0x99,0xB1,0x83,0xC5,0x5D,0xBA,0xB6,0xC5,0x71,0x36,0xF7,0x61,0x3A,0x16,0xC7,0x38,0x34,0xA4,0xCB,0x68,0x64,0xE1,0xC2,0x92,0x6E,0xAD,0x91,0x88,0x0B,0xF2,0x84,0x79,0x38,0x06,0x44,0x94,0x5D,0x9E,0xE9,0x96,0x83,0x53,0x6E,0x79,0x85,0xD9,0x4E,0x9E,0x4F,0xE1,0xD2,0x23,0xB9,0xF9,0x21,0xA6,0x71,0x9D,0xE5,0x12,0x84,0x1A,0xC2,0xB3,0x52,0x52,0x18,0xBA,0x2B,0x5F,0xD3,0x71,0x71,0x98,0x2E,0xBC,0x83,0xD8,0x24,0x7E,0x38,0xCB,0x14,0x5C,0x95,0xF8,0x54,0xC8,0x15,0x72,0x58,0x9C,0xEC,0x0A,0x96,0xD2,0x41,0x43,0x11,0xDB,0xDC,0xED,0x18,0x1E};
const uint8_t diez [] PROGMEM = {0x00,0x08,0xF8,0xD9,0x89,0x68,0x11,0xE4,0x6E,0x84,0x6D,0xA6,0x19,0xB8,0x9B,0x99,0x62,0x84,0x6A,0xD0,0xF6,0x44,0x59,0x4E,0x52,0xA5,0x14,0xB9,0x61,0xBB,0x49,0x43,0xA0,0xE4,0x85,0xE5,0x26,0x0D,0x86,0xDA,0xEB,0x96,0x87,0x34,0x04,0xCA,0x9C,0x8A,0x1E,0xF2,0x10,0xE4,0xB7,0x22,0x69,0x28,0x85,0x49,0xDF,0xA8,0xAD,0xA5,0x16,0x2E,0x75,0xAB,0xB6,0x97,0xD6,0x24,0x47,0xAF,0xDA,0x3E,0x66,0x57,0x1C,0x35,0xE6,0xE8,0xD8,0x5D,0x71,0xD4,0x98,0xE3,0xE5,0x76,0x45,0x51,0x6B,0x8E,0x9B,0x57,0x04,0x77,0xAF,0xC8,0x6E,0x7E,0x15,0xDC,0xBD,0x6C,0x3B,0x05,0x99,0x4B,0xF7,0xB0,0xA2,0x10,0x26,0xA1,0x59,0xED,0x0C,0x5D,0xD4,0x95,0x8A,0x79,0xC9,0x16,0xC0,0x34,0xED,0x04,0x38,0x6E,0x0B,0x01,0xDB,0xFD,0x10,0x60,0xEB,0x6D,0x02,0x6C,0x9D,0xCD,0x80,0xEB,0x3C,0x19,0x70,0x4C,0x3A,0x3C};
const uint8_t veinte [] PROGMEM = {0x00,0x08,0xD8,0x08,0x8D,0xA9,0x0E,0xEC,0xB6,0x47,0x4C,0xA1,0x4A,0xF2,0xED,0x39,0x96,0x83,0x1C,0x54,0x44,0x66,0x4A,0x5E,0x62,0xD2,0x56,0xBD,0xEE,0xF8,0x88,0x55,0x6B,0xD4,0xAA,0xD3,0x23,0x36,0xAD,0x51,0xA3,0x72,0x8E,0xD8,0xB5,0x44,0x8F,0x28,0x59,0xD2,0x50,0x1C,0x3D,0x22,0x67,0x28,0x43,0x60,0x4C,0x8B,0x9C,0xA6,0x0D,0x8E,0x31,0xC9,0x6E,0x8B,0xD9,0x09,0xC6,0x06,0xA5,0x49,0x4E,0xC5,0x94,0xED,0x94,0xD9,0xB9,0x52,0x74,0xB8,0x96,0x6B,0xE3,0x72,0x39,0x6E,0x5E,0x8E,0x8D,0xCB,0xC5,0x85,0x46,0x3A,0x66,0x5E,0x00,0x3D,0x29,0x11,0x1B,0x01,0xDF,0x08,0xA9,0x6A,0xC8,0xD2,0x70,0x73,0x9C,0xFC,0x2C,0x24,0x73,0x4D,0x51,0x09,0xB2,0x90,0xEE,0x15,0xDA,0x29,0xCC,0x5C,0x66,0x46,0x18,0xA5,0xA8,0x0A,0xAA,0x59,0xA1,0x1D,0xE2,0xCA,0xB1,0xA6,0x95,0xB1,0x89,0x3B,0xC3,0xE8,0x52,0xC5,0xF0};
const uint8_t treinta [] PROGMEM = {0x08,0xF8,0x75,0x1C,0x01,0xBF,0x94,0x10,0xE0,0xEA,0x8C,0x24,0x64,0x6D,0xEE,0x1D,0x8E,0x8B,0x90,0xB4,0xA7,0xBD,0xDB,0x6A,0x42,0x36,0x16,0xFE,0xE6,0x78,0x09,0xD9,0x58,0xC6,0xA9,0x93,0x23,0x54,0xA3,0x59,0x2B,0x76,0x8F,0xD8,0x8D,0x46,0xAD,0xD9,0x39,0x62,0xB7,0xE2,0xB5,0x2A,0x7B,0xC9,0x43,0xB3,0xD7,0xA8,0x9C,0xA1,0x0C,0x49,0x5E,0x23,0x4A,0x9A,0x3A,0x04,0xFA,0x34,0xAB,0x69,0xDA,0xA0,0x18,0x9B,0xE4,0xA6,0x98,0x9D,0x50,0x6C,0x52,0xEA,0x64,0x17,0xCC,0x55,0xC1,0x69,0x9C,0xC3,0x75,0x99,0x7B,0xA6,0x72,0x2E,0x57,0xED,0xEE,0xE1,0x4A,0xB9,0x5C,0x9C,0x5B,0x84,0x23,0xE1,0x59,0xB0,0x1D,0xEA,0x72,0x10,0x70,0x05,0x31,0x02,0x7E,0x09,0x75,0x46,0x57,0xEE,0x66,0xE1,0xA4,0xF9,0xD9,0x78,0xDA,0x88,0xED,0x11,0x14,0xE7,0x61,0xCB,0x56,0x46,0x58,0x82,0xA7,0x0F,0xD9,0x69,0x51,0x09,0x9E,0x3E,0x64,0xBB,0xC4,0xC5,0x7B,0x6A,0xB3,0xEC,0x92,0x54,0xEB,0x2E,0x69,0xB4,0x53,0xD2,0xAC,0xA9,0x94,0xCA,0x4E,0xC9,0xF0,0xE5,0x14,0x26,0xC5,0x01,0xD3,0x77,0x28,0x60,0x99,0x0E,0x02,0x5C,0x9D,0x09,0x0F};
const uint8_t cuarenta [] PROGMEM = {0x45,0x75,0x61,0xC3,0x2C,0xD3,0x36,0x2D,0xE4,0x32,0xAE,0x95,0xBB,0xB4,0x94,0xD3,0xB4,0x5B,0xC9,0x31,0x4A,0x8A,0xB0,0x29,0x39,0xC7,0xAC,0xC1,0xC3,0xBB,0x6C,0x1F,0xAB,0x5A,0x8F,0xE8,0xB4,0x33,0xCC,0x6A,0xCC,0x6D,0xC3,0x4E,0x51,0x8B,0x56,0xCF,0x33,0xC7,0x4B,0xA9,0x5A,0x3C,0xCF,0x6C,0x2F,0xA5,0x29,0xF1,0x3C,0xB3,0xBD,0xE4,0xA1,0xD9,0xF3,0xCC,0xF6,0x52,0x86,0x61,0xCB,0x35,0xD9,0x4B,0x1D,0x8A,0x2D,0x56,0xE5,0x0C,0xAD,0x4B,0x76,0x1F,0x95,0x5D,0xCC,0x22,0xC4,0x7D,0x54,0x89,0x73,0x94,0x2C,0xF7,0x08,0x37,0xC6,0x55,0xA2,0x3D,0xDD,0x5C,0x2B,0x4F,0xB2,0x4D,0x37,0x57,0x43,0xBC,0x0C,0xBC,0xD7,0x2C,0x32,0x01,0x8E,0x8A,0x48,0x5E,0x32,0xE1,0x99,0xAE,0xB8,0xF8,0xD9,0x7A,0xDA,0x92,0xED,0x16,0x14,0xEF,0xE9,0xC3,0x72,0x5A,0x54,0xA2,0x65,0x96,0xC8,0x2E,0x71,0x71,0xEE,0x5E,0x42,0x47,0xC5,0xD5,0xAA,0x59,0x84,0xD4,0x07};
const uint8_t cincuenta [] PROGMEM = {0x00,0x48,0x2E,0xDA,0x28,0xC2,0x63,0x23,0xB9,0x15,0xF1,0x14,0xB7,0x8C,0x80,0x36,0x43,0x81,0xE4,0x63,0x4C,0xE0,0x78,0x0C,0x25,0x8F,0x92,0x8A,0x2D,0x16,0x93,0x5A,0x19,0x45,0x9C,0xCB,0x6A,0x5A,0xE7,0x68,0x75,0x46,0xB9,0x18,0x9D,0xA1,0xCF,0x2A,0x93,0x62,0x76,0x8A,0x31,0xC9,0x6E,0x92,0x99,0xB0,0x8C,0x9A,0x37,0x74,0x16,0xB7,0xE5,0x32,0x56,0xD9,0x58,0x34,0x94,0xEB,0x68,0x15,0x66,0xC1,0x34,0xC1,0x6D,0xB1,0x91,0xEB,0x71,0x7A,0x45,0x3A,0x46,0x78,0x9A,0xAD,0x15,0xEE,0x58,0x89,0xB1,0x17,0x5B,0x98,0x92,0x20,0xDA,0x38,0x41,0x36,0x56,0x9A,0x18,0x52,0x3B,0xD7,0x59,0x59,0x62,0xF4,0xE9,0xD6,0xEB,0xF4,0x48,0x45,0x7B,0x78,0xB5,0x9C,0x23,0x77,0x23,0xEE,0x1B,0xB2,0x8F,0x32,0xAC,0x98,0xAF,0xCB,0x5E,0xDA,0xD0,0x62,0xBE,0x2A,0xBB,0xD9,0x4D,0xB1,0xE9,0x8A,0x63,0xE7,0x18,0xE9,0xA5,0xC5,0x75,0x94,0xCB,0xBC,0xA7,0x27,0xCF,0x12,0x2E,0xCA,0x19,0x96,0x5C,0x93,0x78,0x20,0xB7,0x87,0x9B,0x4B,0x08,0x5E,0xD6,0xEE,0x9E,0xE6,0xB8,0xF8,0xD9,0x59,0xC4,0x92,0xED,0x16,0x96,0x60,0x11,0x43,0xB6,0x5B,0x54,0xA2,0x65,0x34,0x99,0x29,0x71,0xF1,0x16,0x5E,0x2C,0x3B,0x25,0xCD,0xBA,0x73,0xAA,0xE4,0x90,0x8E,0x50,0x41,0x6E,0x92,0x5C,0x3A,0xC2,0x84,0x54,0x25,0x16,0xF9,0x70,0x1B,0x3C,0x91,0x16,0x1E};
const uint8_t sesenta [] PROGMEM = {0x00,0x80,0x94,0xE2,0x94,0x4B,0xC3,0x36,0x52,0x5B,0x11,0x2F,0x0E,0x31,0xE8,0x6A,0x23,0xD9,0xCD,0x25,0x22,0xA0,0xD7,0x70,0x26,0xF5,0x6A,0x99,0xCD,0xB1,0x9D,0x5A,0xA4,0x86,0xAD,0xC4,0x69,0x5A,0x56,0x9A,0xF9,0x1A,0x7B,0x19,0x4D,0xB1,0xFB,0x7B,0xE2,0x61,0x36,0xC9,0x11,0xAF,0x51,0x92,0x9D,0x25,0x47,0xAE,0xD8,0x56,0x6E,0xB5,0xEA,0x92,0x2C,0x17,0x7D,0xB5,0x9A,0x55,0x30,0x60,0x60,0x4D,0x1F,0xA9,0xBC,0x54,0x3A,0x89,0x51,0x5B,0xE6,0xB2,0xA5,0x21,0x66,0xAD,0x59,0x27,0x71,0x8E,0xD4,0xB4,0x44,0xAE,0xDA,0x3E,0x72,0x37,0xE2,0xB9,0x2A,0xE7,0x28,0xC3,0xB2,0xC5,0x9A,0xEC,0xA5,0x0D,0x2D,0xE6,0xAB,0xB2,0x87,0xD9,0xA4,0x98,0x8E,0xDA,0x76,0xB6,0x55,0x1E,0xDE,0x92,0x46,0x39,0xDC,0x46,0x5A,0xF3,0x6C,0xE1,0x92,0x98,0xA1,0x25,0xB5,0x88,0x03,0xDA,0x84,0xA5,0xBA,0x04,0x61,0x56,0x1B,0x6A,0x61,0x4E,0x92,0x9F,0xAC,0x85,0x2F,0x39,0x6E,0x41,0xF1,0x16,0x3E,0x6C,0xA7,0x45,0x25,0x5A,0xC6,0xB0,0xED,0x12,0x97,0x60,0xE1,0xCD,0x92,0x53,0x5C,0x8D,0xB9,0x84,0xDA,0x4E,0xC9,0x08,0x61,0xE4,0x26,0x3B,0x64,0x23,0x74,0x6A,0xB8,0x6D,0xB3,0x0D,0xDB,0xA6,0x5B,0x4D,0x10,0x30,0x4D,0xE5,0x03};
const uint8_t setenta [] PROGMEM = {0x48,0x2E,0xDC,0xD4,0xAB,0x1C,0x17,0x2D,0x6A,0xAB,0x5A,0x75,0xB4,0xB4,0x2A,0x25,0xE2,0xDC,0xD1,0x32,0x9B,0x62,0x8F,0x73,0xDB,0xC3,0x6E,0x9A,0x3D,0xCE,0x1D,0x27,0xBB,0x48,0x8E,0x38,0x77,0x25,0x80,0x29,0x8C,0x10,0xF0,0x5B,0x2A,0x02,0x7E,0x6B,0x0D,0x62,0x91,0xEE,0x55,0xE1,0x78,0x88,0x59,0x5A,0xD5,0x69,0xEC,0x25,0x56,0x25,0xD9,0x27,0x49,0x8E,0xD4,0x0D,0x7B,0xAD,0x3A,0x39,0x72,0xD7,0xE2,0xB9,0x2A,0x67,0x29,0x43,0x8B,0xC5,0xAA,0xEC,0xA5,0x75,0x2D,0x66,0x27,0x72,0x8A,0x99,0x85,0xB8,0x8F,0x3A,0x76,0x8E,0x52,0xE1,0x11,0xEE,0xD9,0xB9,0x52,0xB6,0x87,0xBB,0x67,0xE3,0x32,0xB5,0xEE,0x16,0xAA,0x85,0xEB,0xC1,0x76,0x88,0xC7,0x46,0xC0,0x0F,0x8A,0xC1,0x2D,0x3A,0xDC,0xD3,0x1C,0x17,0x3F,0x5B,0x4F,0x1F,0x56,0xDC,0x82,0xE2,0x3D,0x6D,0xD8,0xF6,0x88,0x4A,0xF0,0x8C,0x16,0x59,0x25,0xCE,0x3E,0xC2,0x53,0xE9,0x98,0xB8,0xA8,0x30,0x0B,0x93,0xF3};
const uint8_t ochenta [] PROGMEM = {0x41,0x0E,0xA9,0xD5,0xBA,0xE4,0x0C,0x25,0xE6,0x52,0x99,0x91,0xB3,0xB4,0x14,0xCB,0xA4,0x47,0xCA,0x32,0x52,0x08,0xD3,0x6A,0x2B,0xC3,0x4A,0x4E,0xCD,0xBB,0xEC,0x04,0x3B,0x2A,0xB3,0xEA,0xB4,0x4D,0x80,0x85,0x48,0x11,0xF0,0x53,0x98,0x01,0x4E,0x48,0x0F,0xC0,0xC9,0x93,0x09,0x58,0xCE,0x64,0x88,0x59,0x5A,0xF6,0x2A,0xED,0x23,0x56,0xA9,0x51,0x6B,0x8A,0x8F,0xD4,0x8D,0x78,0xAE,0xC9,0x39,0xCA,0xD0,0x62,0xB1,0x26,0xFB,0xA8,0xC3,0x88,0xC6,0xAA,0xEC,0x61,0x74,0x2D,0x6A,0x6B,0x8A,0x93,0x19,0xB8,0x7B,0x96,0x39,0x71,0x8E,0x54,0x65,0x19,0xEE,0xD9,0xB8,0x5C,0x8D,0x7B,0x98,0x6B,0xE5,0x0A,0x7A,0xE5,0xE6,0x72,0x88,0xDB,0x01,0xE7,0x44,0x24,0x62,0xC0,0x56,0x15,0xC5,0xCB,0xDA,0xC3,0xC7,0x14,0x35,0xBF,0x18,0x4F,0x1B,0x91,0x3D,0x82,0x12,0x3C,0xA3,0x55,0xF1,0x88,0x4A,0xB4,0x8C,0x16,0x59,0x25,0xAE,0xC6,0xDD,0xD2,0x68,0xA7,0xA4,0x05,0x13,0x0E,0x97,0x92,0xD2,0x11,0xCA,0x25,0x42,0x32,0xB2,0x87,0x2F,0xB7,0xCC,0xC8,0x0F};
const uint8_t noventa [] PROGMEM = {0x00,0x40,0x34,0x54,0x2A,0xDD,0x3C,0xB5,0xD2,0x50,0xEA,0xB4,0x96,0xDA,0x46,0xC3,0xB1,0xD2,0x5B,0x66,0x27,0x55,0xEA,0x08,0x1F,0x77,0xBC,0xD4,0xAC,0x43,0x75,0x42,0xF6,0xD2,0xB2,0x4B,0xD5,0x2E,0xDA,0xCB,0xC8,0xBE,0x8D,0xBB,0xE5,0x34,0x33,0x85,0x11,0xEE,0x15,0x9B,0xEC,0xE4,0xC6,0xC8,0xD7,0x8C,0x72,0xBC,0x48,0x17,0xA9,0x38,0x49,0x4D,0xCE,0x4D,0xB2,0xED,0x2C,0x25,0x1B,0x0B,0x9B,0x76,0x7C,0xE4,0x2A,0x35,0x62,0xC3,0xF1,0x91,0xBA,0x11,0xCF,0x75,0x25,0x47,0x1E,0x5A,0x3C,0xD7,0xE4,0x1C,0x65,0x18,0xB6,0x5C,0x53,0xBC,0xB4,0xAE,0x59,0x7D,0x55,0xF6,0x30,0x9A,0x12,0xB3,0x55,0x25,0xCE,0x51,0xCA,0xC3,0x4A,0x53,0x2B,0x97,0xB9,0x48,0x2B,0x9A,0x25,0x3C,0x12,0x33,0x2D,0xA5,0x12,0xF3,0x60,0xAE,0x70,0xD7,0x84,0x10,0xDC,0xA2,0x3D,0x2C,0x34,0x49,0xF1,0xB3,0xB3,0x8C,0x61,0x3B,0x2D,0x28,0xDE,0xC2,0x87,0xEC,0xB4,0xB0,0x44,0xCB,0x18,0xB2,0x52,0xE2,0xE2,0xCD,0xAD,0x58,0x76,0x4A,0x9A,0x35,0xE5,0x34,0x39,0x29,0x19,0xB1,0x8C,0xC3,0x25,0x3B,0x60,0xFA,0x4E,0x01,0x4C,0x53,0x81,0x92,0x6E,0xD2,0x7D,0x22,0xC9,0x03};
const uint8_t menos [] PROGMEM = {0x00,0x48,0xC5,0x61,0xBD,0x42,0xE3,0x08,0x05,0xB6,0xC8,0xF2,0x94,0x6C,0x64,0x92,0xD2,0x3B,0xD2,0x4A,0x90,0x58,0x28,0xCF,0x2C,0xDB,0x4B,0x2C,0x4A,0x3D,0xDA,0x15,0x1F,0xB1,0x2B,0xF1,0x1C,0x93,0x73,0xC4,0xAE,0xC5,0x6B,0x54,0xCE,0x91,0x87,0x96,0xA8,0x51,0x39,0x47,0x19,0x5A,0x3C,0xC7,0x64,0x1D,0x6D,0x68,0xB6,0x1C,0x95,0xBD,0xCC,0xA1,0xD9,0x62,0x4C,0x76,0x71,0x2B,0x67,0xB3,0x31,0x25,0xC6,0x15,0xD6,0xD3,0x4A,0x1A,0x1B,0x57,0x18,0x4F,0x2B,0x6E,0x94,0xDC,0x2C,0xD5,0x74,0x5D,0x4E,0xF3,0xAA,0x31,0xE7,0x0E,0x39,0xCD,0xCF,0x2E,0x4C,0x32,0xE5,0x94,0x20,0xC5,0x52,0xCE,0x92,0x93,0xA2,0x58,0x93,0xA5,0x92,0x8E,0x8B,0x63,0x0B,0xD2,0x0E,0x26,0x26,0x0E,0xC5,0xC8,0xDA,0x54,0x9B,0x28,0x99,0x14,0x71,0x75,0x6C,0x82,0xE6,0xDB,0x33,0xD4,0x21,0xD9,0x5A,0x6E,0x3B,0x8E,0x58,0x00,0x40,0x80,0x65,0x3A,0x11,0x30,0x6D,0x1B,0x3C};
const uint8_t mas [] PROGMEM = {0x00,0x48,0x85,0xA5,0xBC,0xC3,0x23,0x0B,0x15,0x67,0xF7,0x89,0x8A,0x6C,0x14,0x1A,0xDD,0x3B,0xDA,0xB1,0x91,0x59,0x72,0xEF,0xAC,0xC4,0x41,0xB2,0xDE,0x34,0x2B,0x1C,0x2F,0xA9,0x24,0xB7,0x58,0x75,0x7C,0xE4,0x1A,0xD2,0x7C,0xD4,0xF1,0x51,0x6A,0x4C,0xF3,0x11,0xDB,0x47,0xAB,0x29,0xDC,0x47,0x6C,0x1F,0xA3,0xC6,0x74,0x1B,0xB5,0xBD,0xEC,0x1A,0x33,0x6C,0xC4,0xF6,0xF2,0x6A,0x4C,0xB7,0x56,0xDB,0xCB,0xAF,0x21,0x42,0x47,0x6C,0xB7,0xA0,0x86,0x70,0x1D,0xB6,0x1D,0xA2,0x1C,0xD4,0xBD,0x31,0x8A,0x89,0xAA,0x71,0xE3,0x36,0xCB,0xC2,0xEE,0xD2,0xD4,0x5C,0x6D,0x23,0xAD,0xFB,0xF4,0x08,0x95,0x0D,0x00,0x08,0x58,0xC1,0x9B,0x1C,0xD3,0x46,0xC5,0xB4,0x1D,0xF4,0x0D,0x97,0x19,0x95,0x6E,0xE0,0x01};
const uint8_t de [] PROGMEM = {0x80,0x80,0x1F,0x8D,0x88,0x91,0x80,0xF7,0x65,0xC6,0x66,0x46,0x00,0xB5,0xED,0x61,0x89,0x69,0x11,0xD4,0x74,0x56,0x6C,0x27,0x47,0xE9,0x9A,0x5D,0x72,0x9A,0x1C,0xB5,0x57,0x9D,0xD9,0x5A,0x72,0x96,0x5A,0x7D,0x9A,0x64,0x29,0x55,0x4A,0xCE,0x9A,0xE3,0xA3,0x35,0xC5,0xD1,0x6B,0xB6,0x97,0xD1,0x35,0x45,0xAD,0xD9,0x5E,0x76,0x57,0x94,0x3D,0x66,0xBB,0x79,0x55,0x70,0x4F,0x8B,0xAC,0xE6,0x57,0xC1,0xD3,0xAD,0xB6,0x52,0x50,0x38,0x4F,0x97,0xD8,0x76,0x61,0x66,0x32,0x63,0xA2,0x0A,0x01,0xDF,0x99,0x3E};
const uint8_t y [] PROGMEM = {0x08,0xF8,0x7D,0x13,0x01,0xBF,0x4D,0x20,0xE0,0xB7,0x0D,0x27,0x36,0x42,0xB9,0x6B,0x72,0x9A,0xD8,0x09,0xF9,0xAE,0x50,0x19,0x62,0x27,0xE4,0xB7,0x22,0x65,0x88,0x1D,0x53,0xEC,0x88,0xD4,0x21,0x76,0x42,0xBE,0x2B,0x52,0x87,0xD4,0x09,0xF9,0xAE,0x48,0x19,0x72,0x27,0x64,0x7B,0x42,0x75,0x28,0x0D,0x93,0xDF,0x32,0xD5,0x66,0x34,0x4C,0x71,0x4B,0x74,0x8B,0x5D,0x09,0xE5,0x2D,0xD1,0x4D,0x5E,0x21,0xDC,0x37,0x44,0xD7,0xF9,0x91,0xD8,0x9C,0xA3,0x52,0x17,0x24,0xA4,0xB3,0x8E,0x9A,0x5D,0xD4,0x10,0xC7,0x38,0x79,0x46,0xD5,0x40,0x6C,0x9D,0x2E,0xFB,0x01};
const uint8_t metros [] PROGMEM = {0x41,0x53,0x2E,0xC4,0x2A,0xD3,0x18,0x95,0xE6,0xD0,0xCA,0x4C,0xE2,0x54,0x9A,0xC2,0x3A,0x2A,0x6E,0x90,0xB9,0x4F,0xF7,0xAC,0xB8,0x43,0x2E,0x52,0xDD,0x2A,0x64,0x1F,0xA5,0x6B,0x71,0x1F,0x97,0x7D,0xD4,0x61,0xC5,0x62,0x5D,0xF6,0x31,0x86,0x65,0x8B,0x75,0xD9,0xC7,0x9C,0x96,0xCD,0xD7,0x65,0x2F,0x67,0x18,0x36,0x5F,0x93,0xDD,0xBC,0x2A,0x39,0xFC,0xCC,0xB6,0x09,0x32,0x17,0xF7,0x2E,0xC9,0x08,0x58,0xDC,0x04,0xD8,0xDF,0x6D,0x7A,0x84,0x3A,0x0E,0x4E,0x53,0x66,0x1A,0xE6,0xA4,0xB8,0xC9,0x49,0xC4,0x8A,0xE2,0xE0,0x25,0x6D,0x6E,0xDD,0xB2,0x8B,0x1F,0xBD,0xA4,0x8F,0x5B,0x29,0x41,0x0C,0x16,0xD6,0x61,0x35,0x85,0x21,0x79,0xC8,0x84,0xD4,0x10,0x85,0xE2,0x4E,0xA7,0x8C,0x5D,0x1C,0xAA,0x9B,0x9C,0x31,0x56,0x71,0xC8,0x4E,0x31,0xAA,0x4A,0x24,0xD9,0x97,0x6A,0x08,0xED,0x07};
const uint8_t centimetros [] PROGMEM = {0x00,0x4E,0x4D,0xDC,0xCA,0x56,0x63,0x2F,0x2D,0x4B,0xCD,0x38,0x89,0x7D,0x8C,0xA6,0xC5,0xEC,0xCC,0xCE,0xB2,0x9A,0x14,0xD7,0x55,0x3B,0xC5,0x0E,0x42,0xC3,0x46,0x5C,0x07,0x9B,0x39,0x0F,0x4B,0x6D,0x64,0x1C,0x98,0x3A,0x2C,0xC3,0x25,0x71,0x04,0xB9,0x0C,0x4F,0x25,0x08,0x78,0x92,0xD8,0x49,0x55,0xAB,0xBB,0x89,0xEB,0xA1,0x74,0x89,0x1A,0x17,0xB2,0x96,0x3A,0x24,0x4A,0x5E,0xC8,0x1A,0xDA,0x10,0xA8,0x7D,0x21,0x69,0x18,0x5D,0xA0,0xCE,0x1A,0xDD,0x66,0x65,0xC6,0x59,0xEE,0x6E,0x92,0x23,0x6C,0x6A,0x78,0xD6,0x49,0xAE,0x51,0xE1,0xEE,0x69,0x67,0x79,0x4D,0xB1,0x47,0x85,0xEC,0xE5,0x77,0xC5,0xEE,0x6B,0x72,0x46,0x58,0x25,0xBB,0x9F,0x2A,0x4E,0x51,0x16,0x92,0xBE,0x26,0x9B,0x65,0x5D,0x8A,0xA8,0x95,0x13,0x08,0x4E,0x75,0xE5,0xE6,0xEA,0xA4,0xF9,0xD1,0x5A,0xD8,0xAA,0xEC,0xE2,0x67,0x6B,0x66,0x55,0x56,0x5A,0x10,0xBD,0xBA,0x4F,0x58,0x69,0x61,0x0C,0x96,0xDA,0x61,0x35,0x45,0x21,0x79,0xF0,0x99,0x14,0x17,0x87,0xAC,0x6A,0x13,0xB4,0x5D,0x9C,0x5D,0x09,0x87,0x5B,0x41,0x69,0xB1,0xE3,0x9A,0x26,0xE9,0x01};
const uint8_t porciento[] PROGMEM = {0xE0,0x94,0x6A,0xDD,0xCD,0x2D,0x4E,0x52,0x7D,0x6A,0xA7,0x5C,0xB9,0x4D,0x0B,0x7E,0x82,0x62,0xAD,0x0C,0x2D,0xC6,0x36,0x8E,0xB5,0xB2,0x8C,0x94,0xCA,0xA4,0xC6,0xCA,0x30,0x53,0x56,0xB7,0x89,0xA8,0xC1,0xCA,0x45,0xD4,0xDA,0xAB,0x24,0x3B,0x7A,0xF1,0x98,0xB0,0x93,0x9C,0x42,0xDD,0x2C,0xCB,0x96,0x03,0x96,0x0E,0x66,0x6E,0x0F,0xE9,0xB7,0x02,0x19,0x00,0xED,0xE3,0x4D,0xB1,0x42,0x6E,0x23,0x56,0xC9,0x62,0xD7,0x89,0x8A,0xD8,0x39,0x5A,0xBE,0x5B,0x6E,0xE2,0xD4,0xC8,0x75,0x2E,0x7B,0x00,0x53,0x11,0x2F,0x71,0x28,0xB2,0x39,0x93,0xBC,0xA4,0x26,0x39,0x66,0xD5,0xF6,0x91,0x87,0x12,0xAF,0x55,0xD9,0x47,0xE9,0x5A,0xBC,0x46,0x65,0x1F,0x6D,0x18,0x31,0x5F,0x93,0xBD,0x8C,0xAE,0xD5,0x74,0xCD,0x76,0xB3,0x9A,0x12,0x93,0x55,0xC5,0xCE,0x56,0xC6,0x3D,0xCA,0xDC,0x18,0x87,0x79,0x0F,0x2B,0x69,0x24,0x5C,0x94,0x32,0x2C,0x35,0x21,0x71,0x41,0xEE,0xB0,0x50,0x57,0x28,0x08,0xD8,0x23,0x32,0x9D,0x80,0xB3,0xAA,0x33,0x77,0xB3,0x38,0xC5,0x4F,0x4E,0xC3,0xCF,0xE5,0x94,0x20,0x39,0x77,0x9D,0x64,0x92,0xC2,0x90,0xC3,0xB5,0x8B,0x51,0x88,0x43,0x49,0xC7,0x2D,0xC6,0x26,0x09,0xC3,0x58,0xA7,0xE1,0x88,0x34,0xA4,0x24,0xA9,0x90,0xCB,0x92,0x6C,0x56,0x30,0x8D,0x0E,0xCA,0x3A,0xDB,0xA1,0x0E,0xDB,0x0F};

byte palabra = 1;
bool clv = 0;
void setup() 
{
    Serial.begin(9600);
}
void loop()
{
    for(int a = 6; a < 31; a++)
      sonido(a);
    delay(200);
}

void sonido(uint8_t numero)
{
    switch (numero)
    {
    case 1:
        voice.say(rojo);
        break;
    case 2:
        voice.say(verde);
        break;
    case 3:
        voice.say(azul);
        break;
    case 4:
        voice.say(cuidado);
        break;
    case 5:
        voice.say(blanco);
        break;
    case 6:
        voice.say(un);
        voice.say(metros);
        break;
    case 7:
        voice.say(dos);
        voice.say(metros);
        break;
    case 8:
        voice.say(tres);
        voice.say(metros);
        break;
    case 9:
        voice.say(cuatro);
        voice.say(metros);
        break;
    case 10:
        voice.say(diez);
        voice.say(centimetros);
        break;
    case 11:
        voice.say(veinte);
        voice.say(centimetros);
        break;   
    case 12:
        voice.say(treinta);
        voice.say(centimetros);
        break; 
    case 13:
        voice.say(cuarenta);
        voice.say(centimetros);
        break;   
    case 14:
        voice.say(cincuenta);
        voice.say(centimetros);
        break;
    case 15:
        voice.say(sesenta);
        voice.say(centimetros);
        break;
    case 16:
        voice.say(setenta);
        voice.say(centimetros);
        break;
    case 17:
        voice.say(ochenta);
        voice.say(centimetros);
        break;
    case 18:
        voice.say(noventa);
        voice.say(centimetros);
        break;
    case 19:
        voice.say(diez);
        voice.say(porciento);
        break;
    case 20:
        voice.say(veinte);
        voice.say(porciento);
        break;   
    case 21:
        voice.say(treinta);
        voice.say(porciento);
        break; 
    case 22:
        voice.say(cuarenta);
        voice.say(porciento);
        break;   
    case 23:
        voice.say(cincuenta);
        voice.say(porciento);
        break;
    case 24:
        voice.say(sesenta);
        voice.say(porciento);
        break;
    case 25:
        voice.say(setenta);
        voice.say(porciento);
        break;
    case 26:
        voice.say(ochenta);
        voice.say(porciento);
        break;
    case 27:
        voice.say(noventa);
        voice.say(porciento);
        break;
    case 28:
        voice.say(menos);
        voice.say(de);
        voice.say(diez);
        voice.say(porciento);
        break;
    case 29:
        voice.say(menos);
        voice.say(de);
        voice.say(cinco);
        voice.say(porciento);
        break;
    case 30:
        voice.say(y);
        break;
    case 31:
        voice.say(errorAlTomarMedida);
        break;   
    case 32:
        voice.say(modoAhorroActivado);
        break; 
    case 33:
        voice.say(modoAhorroDesactivado);
        break;
    case 34:
        voice.say(conexionCargador);
        break; 
    case 35:
        voice.say(desconexionCargador);
        break; 
    }
}