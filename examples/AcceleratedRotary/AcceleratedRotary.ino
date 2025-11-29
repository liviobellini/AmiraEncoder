//AmiraEncoder accelerated rotary encoder.
//This example shows how to use a rotary encoder with accelerated increment, enjoy. :-)
#include <Arduino.h>
#include <AmiraEncoder.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
//-------------------------------------------------PIN DEFINITION-----------------------------------------------
#define DT 4                  //Data encoder.
#define CLK 5                 //Clock encoder.
///////////////////////OBJECTS DEFINITION//////////////////////
hd44780_I2Cexp lcd;                                                          //Set object LCD with address auto-detect.
Encoder myEncoder(DT, CLK, EXTERNAL, 25);                                    //Set object for rotary encoder with external pullup resistors and sensitivity 25.
//IMPORTANT: If you don't write anything in cosntructor then default configuration for the pull-up resistors will be INTERNAL.
//IMPORTANT: If you don't write anything in constructor then the default sensitivity value will be 0ms.
///////////////////////ARDUINO FUNCTIONS///////////////////////
void setup() {  
  lcd.begin(16, 2);                                                          //Initialize the LCD display with 16 columns and 2 rows.
  lcd.setBacklight(255);                                                     //Turn on lcd backlight.
  myEncoder.begin();                                                         //Execute setup for rotary encoder and read the state.
  myEncoder.setStep(1);  //Set the normal step when encoder is not accelerated, YOU CAN RECALL THIS FUNCTION ANYWHERE AND AS MANY TIMES AS YOU WANT TO CHANGE THE NORMAL STEP VALUE.
  myEncoder.setAccel(8); //Set the long step when encoder is accelerated YOU CAN RECALL THIS FUNCTION ANYWHERE AND AS MANY TIMES AS YOU WANT TO CHANGE THE LONG STEP VALUE.
  //IMPORTANT: if you don't call setStep then default value will be 1.
  //IMPORTANT: if you don't call setAccel then default value will be 1.
  lcd.clear();
  lcd.home();
  lcd.print("VOLUME:    db");
  lcd.setCursor(0, 1);
  lcd.print("accel example");
}

void loop() {
  int vol = -50;
  int prevVol = -50;
  lcd.setCursor(8, 0);
  lcd.print(vol);
  while(true){
    vol = myEncoder.loop(vol);                                               //Check if someone is touching encoder.
    if(vol <= -70) {                                                         //Check minimum and maximum value.
      vol = -70;
    } else if(vol >= 6) {
      vol = 6;
    }
    if(prevVol != vol) {
      lcd.setCursor(8, 0);
      lcd.print("   ");
      lcd.setCursor(8, 0);
      lcd.print(vol);
      prevVol = vol;
    }
  }
}
