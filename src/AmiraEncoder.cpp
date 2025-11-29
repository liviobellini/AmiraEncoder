#include "AmiraEncoder.h"

Encoder::Encoder(uint8_t _pinA, uint8_t _pinB, uint8_t _pullup, byte _encSens) {
  pinA = _pinA;
  pinB = _pinB;
  pullup = _pullup;
  encSens = _encSens;
  normStep = 1;
  longStep = 1;
  state = 0;
  dir = DIR_NONE;
  value = 0;
  currentRotation = 0;
  lastRotation = 0;
}

void Encoder::begin() {
  if (pullup == INTERNAL) {
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
  } else {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
  }
  state = (digitalRead(pinA) << 1) | digitalRead(pinB);
}

int Encoder::loop(int _value) {
  unsigned char newState = (digitalRead(pinA) << 1) | digitalRead(pinB);
  unsigned char transition = (state << 2) | newState;
  int encStep = normStep;
  dir = DIR_NONE;
  value = _value;
  switch (transition) {
    
    //case 0b0001: dir = DIR_CW; break; // 00 -> 01
    //case 0b0111: dir = DIR_CW; break; // 01 -> 11
    case 0b1110: dir = DIR_CW; break; // 11 -> 10 (final state)
    //case 0b1000: dir = DIR_CW; break; // 10 -> 00
    
    //case 0b0010: dir = DIR_CCW; break; // 00 -> 10
    //case 0b1011: dir = DIR_CCW; break; // 10 -> 11
    case 0b1101: dir = DIR_CCW; break; // 11 -> 01 (final state)
    //case 0b0100: dir = DIR_CCW; break; // 01 -> 00
  
  }
  state = newState;
  if(encSens != 0) {
    if (dir == DIR_CW || dir == DIR_CCW) {
      lastRotation = currentRotation;
      currentRotation = millis();
    } else if(dir == DIR_NONE) {
      return value;
    }
    if((currentRotation - lastRotation) < encSens){
      encStep = longStep;
    }
    encStep = min(encStep, longStep);   //Force encStep to longStep to prevent errors.
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

uint8_t Encoder::setStep(uint8_t _normStep) {
  return normStep = _normStep;
}

uint8_t Encoder::setAccel(uint8_t _longStep) {
  return longStep = _longStep;
}

unsigned char Encoder::getDirection() {
  return dir;
}