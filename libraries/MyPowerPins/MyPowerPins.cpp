/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyPowerPins.h"

MyPowerPins::MyPowerPins(
  ) : MyPowerPins(0, 0){
}

MyPowerPins::MyPowerPins(
  unsigned int pin_vcc
  ) : MyPowerPins(pin_vcc, 0){
}

MyPowerPins::MyPowerPins(
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) {
  if(pin_vcc > 0){
    pinMode(pin_vcc, OUTPUT);
    digitalWrite(pin_vcc, HIGH);
  }
  if(pin_gnd > 0){
    pinMode(pin_gnd, OUTPUT);
    digitalWrite(pin_gnd, LOW);
  }
}
