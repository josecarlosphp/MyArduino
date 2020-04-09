/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBinarySensor.h"

MyBinarySensor::MyBinarySensor(
  unsigned int pin_out,
  unsigned int pin_vcc = 0,
  unsigned int pin_gnd = 0
  ){
  pinMode(pin_out, INPUT);

  if(pin_vcc > 0){
    pinMode(pin_vcc, OUTPUT);
    digitalWrite(pin_vcc, HIGH);
  }

  if(pin_gnd > 0){
    pinMode(pin_gnd, OUTPUT);
    digitalWrite(pin_gnd, LOW);
  }

  this->pin_out = pin_out;
}

int MyBinarySensor::Read(){
  return digitalRead(this->pin_out);
}
