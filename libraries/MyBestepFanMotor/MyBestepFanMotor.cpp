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
  ) : powerPins(pin_vcc, pin_gnd) {
  this->pin_ina = pin_ina;
  this->pin_inb = pin_inb;

  pinMode(this->pin_ina, OUTPUT);
  pinMode(this->pin_inb, OUTPUT);
}

void MyBestepFanMotor::forward(unsigned int speed){
  analogWrite(this->pin_ina, speed);
  analogWrite(this->pin_inb, 0);
}

void MyBestepFanMotor::reverse(unsigned int speed){
  analogWrite(this->pin_ina, 0);
  analogWrite(this->pin_inb, speed);
}

void MyBestepFanMotor::stop(){
  digitalWrite(this->pin_ina, LOW);
  digitalWrite(this->pin_inb, LOW);
}
