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
    int32_t loop(int32_t _value);
    void setStep(uint8_t _normStep);
    void setAccel(uint16_t _longStep);
    unsigned char getDirection();
  private:
    uint8_t pinA;
    uint8_t pinB;
    uint8_t pullup;
    byte encSens;                     //Encoder sensitivity. The higher the value, the earlier the acceleration kicks in.
    uint8_t normStep;                 //Normal step is a positive number (0 <-> 255).
    uint16_t longStep;                //Long step is a large positive number (0 <-> 65535).
    unsigned char state;              //Save the state on the table.
    unsigned char dir;                //Rotation direction.
    int32_t value;                    //Value is a very large negative and positive number (−2.147.483.648 <-> +2.147.483.647), this prevents overflow problems.
    unsigned long lastMove;           //Save the last encoder movement time.
};

#endif



