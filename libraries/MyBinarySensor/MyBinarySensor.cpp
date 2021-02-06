/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBinarySensor.h"

MyBinarySensor::MyBinarySensor(
  unsigned int pin_out,
  unsigned int pin_vcc = 0,
  unsigned int pin_gnd = 0
  ) : powerPins(pin_vcc, pin_gnd) {
  pinMode(pin_out, INPUT);

  this->pin_out = pin_out;
}

int MyBinarySensor::Read(){
  return digitalRead(this->pin_out);
}
