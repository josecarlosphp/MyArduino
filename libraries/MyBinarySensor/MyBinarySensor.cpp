/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBinarySensor.h"

MyBinarySensor::MyBinarySensor(
  unsigned int pin_out
  ) : MyBinarySensor(pin_out, 0, 0){
}

MyBinarySensor::MyBinarySensor(
  unsigned int pin_out,
  unsigned int pin_vcc
  ) : MyBinarySensor(pin_out, pin_vcc, 0){
}

MyBinarySensor::MyBinarySensor(
  unsigned int pin_out,
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) : powerPins(pin_vcc, pin_gnd){
  pinMode(pin_out, INPUT_PULLUP);
  this->pin_out = pin_out;
}

bool MyBinarySensor::Read(){
  return digitalRead(this->pin_out);
}