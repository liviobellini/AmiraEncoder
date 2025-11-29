//AmiraEncoder direction rotary encoder.
//This example shows how to use getDirection function to know how you are turning the rotary encoder, enjoy. :-)
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
Encoder myEncoder(DT, CLK, EXTERNAL);                                        //Set object for rotary encoder with external pullup resistors and no sensitivity.
//IMPORTANT: If you don't write anything in cosntructor then default configuration for the pull-up resistors will be INTERNAL.
//IMPORTANT: If you don't write anything in constructor then the default sensitivity value will be 0ms.
///////////////////////ARDUINO FUNCTIONS///////////////////////
void setup() {  
  lcd.begin(16, 2);                                                          //Initialize the LCD display with 16 columns and 2 rows.
  lcd.setBacklight(255);                                                     //Turn on lcd backlight.
  myEncoder.begin();                                                         //Execute setup for rotary encoder.
  //IMPORTANT: if you don't call setStep then default values will be 1.
  //IMPORTANT: if you don't call setAccel then default values will be 1.
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("get direction");
}

void loop() {
  int vol = 0;
  int prevVol = 0;
  while(true){
    vol = myEncoder.loop(vol);                                               //Check if someone is touching encoder.
    if(prevVol != vol) {
      lcd.home();
      lcd.print("                ");
      lcd.home();
      unsigned char direction = myEncoder.getDirection();
      if(direction == DIR_CW) {
        lcd.print("=>            CW");
      } else if(direction == DIR_CCW) {
        lcd.print("<=           CCW");
      }
      prevVol = vol;
    }
  }
}