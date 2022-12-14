/*
 * Board: DigiSpark - default 16.5Mhz
 * Programmer: Micronucleus
 * External library used: Arduino EEPROM Library
 */

#include "EEPROM.h"

#define OPTRON_OUT  PB0
#define LED_BUILTIN PB1
#define LAMP_IN     PB2

#define lamp_is_on        (digitalRead(LAMP_IN) ? false : true)
#define optron_on         digitalWrite(OPTRON_OUT, HIGH) 
#define optron_off        digitalWrite(OPTRON_OUT, LOW) 
#define led_on            digitalWrite(LED_BUILTIN, HIGH) 
#define led_off           digitalWrite(LED_BUILTIN, LOW) 
#define save_ee_lamp_on   EEPROM.put(0, 1)
#define save_ee_lamp_off  EEPROM.put(0, 0)
#define ee_lamp_is_on     ((EEPROM.read(0)==1) ? true : false)


void setup() {
  pinMode(OPTRON_OUT, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LAMP_IN, INPUT_PULLUP);

  delay(2000);

  if(ee_lamp_is_on && !lamp_is_on){
    led_on; 
    optron_on;
    delay(1000);
    optron_off;
  }else{
    led_off;
  }
  
}

void loop() {
  
  delay(500);    

  if(lamp_is_on && !ee_lamp_is_on){
      save_ee_lamp_on;
      led_on;
  }


  if(!lamp_is_on && ee_lamp_is_on){
      save_ee_lamp_off;
      led_off;
  }

}
