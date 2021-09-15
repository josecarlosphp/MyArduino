/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyDC.h"

MyDC::MyDC(
  unsigned int pin_ina,
  unsigned int pin_inb
  ) {
  this->pin_ina = pin_ina;
  this->pin_inb = pin_inb;

  pinMode(this->pin_ina, OUTPUT);
  pinMode(this->pin_inb, OUTPUT);
}

void MyDC::forward(unsigned int speed){
  analogWrite(this->pin_ina, speed);
  analogWrite(this->pin_inb, 0);
}

void MyDC::reverse(unsigned int speed){
  analogWrite(this->pin_ina, 0);
  analogWrite(this->pin_inb, speed);
}

void MyDC::stop(){
  digitalWrite(this->pin_ina, LOW);
  digitalWrite(this->pin_inb, LOW);
}
