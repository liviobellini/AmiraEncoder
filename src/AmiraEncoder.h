#ifndef AMIRAENCODER_H
#define AMIRAENCODER_H

#include <Arduino.h>

#define INTERNAL 2
#define EXTERNAL 3
#define DIR_NONE 0x0
#define DIR_CW   0x10
#define DIR_CCW  0x20
#define R_START  0x0

#ifdef HALF_STEP								      //Use the half-step state table (emits a code at 00 and 11).
#define R_CCW_BEGIN 0x1
#define R_CW_BEGIN 0x2
#define R_START_M 0x3
#define R_CW_BEGIN_M 0x4
#define R_CCW_BEGIN_M 0x5
#else										              //Use the full-step state table (emits a code at 00 only).
#define R_CW_FINAL 0x1
#define R_CW_BEGIN 0x2
#define R_CW_NEXT 0x3
#define R_CCW_BEGIN 0x4
#define R_CCW_FINAL 0x5
#define R_CCW_NEXT 0x6
#endif

class Encoder {
  public:
    Encoder(uint8_t _pinA, uint8_t _pinB, uint8_t _pullup = INTERNAL, byte _encSens = 0);
    int loop(int _value);
    void setStep(uint8_t _normStep);
    void setAccel(uint8_t _longStep);
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
};

#endif
