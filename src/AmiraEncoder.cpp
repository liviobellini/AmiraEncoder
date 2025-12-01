#include "AmiraEncoder.h"

#ifdef HALF_STEP								      //Use the half-step state table (emits a code at 00 and 11).
const unsigned char ttable[6][4] = {
  {R_START_M,            R_CW_BEGIN,     R_CCW_BEGIN,  R_START},
  {R_START_M | DIR_CCW, R_START,        R_CCW_BEGIN,  R_START},
  {R_START_M | DIR_CW,  R_CW_BEGIN,     R_START,      R_START},
  {R_START_M,            R_CCW_BEGIN_M,  R_CW_BEGIN_M, R_START},
  {R_START_M,            R_START_M,      R_CW_BEGIN_M, R_START | DIR_CW},
  {R_START_M,            R_CCW_BEGIN_M,  R_START_M,    R_START | DIR_CCW},
};
#else										              //Use the full-step state table (emits a code at 00 only).
const unsigned char ttable[7][4] = {
  {R_START,    R_CW_BEGIN,  R_CCW_BEGIN, R_START},
  {R_CW_NEXT,  R_START,     R_CW_FINAL,  R_START | DIR_CW},
  {R_CW_NEXT,  R_CW_BEGIN,  R_START,     R_START},
  {R_CW_NEXT,  R_CW_BEGIN,  R_CW_FINAL,  R_START},
  {R_CCW_NEXT, R_START,     R_CCW_BEGIN, R_START},
  {R_CCW_NEXT, R_CCW_FINAL, R_START,     R_START | DIR_CCW},
  {R_CCW_NEXT, R_CCW_FINAL, R_CCW_BEGIN, R_START},
};
#endif

Encoder::Encoder(uint8_t _pinA, uint8_t _pinB, uint8_t _pullup, byte _encSens) {
  pinA = _pinA;
  pinB = _pinB;
  pullup = _pullup;
  encSens = _encSens;
  normStep = 1;
  longStep = 0;
  dir = DIR_NONE;
  value = 0;
  lastMove = 0;
  if (pullup == INTERNAL) {
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
  } else {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
  }
  state = R_START;
}

int32_t Encoder::loop(int32_t _value) {
  int encStep = normStep;
  value = _value;
  unsigned char pinstate = (digitalRead(pinB) << 1) | digitalRead(pinA);
  state = ttable[state & 0xf][pinstate];
  dir = state & 0x30; 
  if(encSens != 0 && dir != DIR_NONE && longStep != 0) {
    unsigned long currentMove = millis();
    unsigned long deltaMove = currentMove - lastMove;
    lastMove = currentMove;
    if(deltaMove < encSens){
      encStep = longStep;
    } else {
      encStep = normStep;
    }
  }
  if (dir == DIR_CW) {
    value += encStep;
  } else if (dir == DIR_CCW) {
    value -= encStep;
  } else if (dir == DIR_NONE){
    value = value;
  }
  return value;
}

void Encoder::setStep(uint8_t _normStep) {
  normStep = _normStep;  
  return;
}

void Encoder::setAccel(uint16_t _longStep) {
  longStep = _longStep;
  return;
}

unsigned char Encoder::getDirection() {
  return dir;
}
