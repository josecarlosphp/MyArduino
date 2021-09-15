/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBestepFanMotor.h"

MyBestepFanMotor::MyBestepFanMotor(
  unsigned int pin_ina,
  unsigned int pin_inb,
  unsigned int pin_vcc = 0,
  unsigned int pin_gnd = 0
  ) : powerPins(pin_vcc, pin_gnd), motor(pin_ina, pin_inb) {}

void MyBestepFanMotor::forward(unsigned int speed){
  this->motor.forward(speed);
}

void MyBestepFanMotor::reverse(unsigned int speed){
  this->motor.reverse(speed);
}

void MyBestepFanMotor::stop(){
  this->motor.stop();
}
