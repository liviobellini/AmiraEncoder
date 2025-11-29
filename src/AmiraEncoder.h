#ifndef AMIRAENCODER_H
#define AMIRAENCODER_H

#include <Arduino.h>

#define INTERNAL 2
#define EXTERNAL 3
#define DIR_NONE 0x00
#define DIR_CW   0x10
#define DIR_CCW  0x20

class Encoder {
  public:
    Encoder(uint8_t _pinA, uint8_t _pinB, uint8_t _pullup = INTERNAL, byte _encSens = 0);
    void begin();
    int loop(int _value);
    uint8_t setStep(uint8_t _normStep);
    uint8_t setAccel(uint8_t _longStep);
    unsigned char getDirection();
  private:
    uint8_t pinA;
    uint8_t pinB;
    uint8_t pullup;
    byte encSens;
    uint8_t normStep;
    uint8_t longStep;
    unsigned char state;
    unsigned char dir;
    int value;
    unsigned long currentRotation;
    unsigned long lastRotation;
};

#endif
