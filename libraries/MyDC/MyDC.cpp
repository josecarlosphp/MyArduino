/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyDC.h"

MyDC::MyDC(
  unsigned int pin_ina,
  unsigned int pin_inb
  ) : MyDC(pin_ina, pin_inb, 0){
}

MyDC::MyDC(
  unsigned int pin_ina,
  unsigned int pin_inb,
  unsigned int pin_pwm
  ) {
  this->pin_ina = pin_ina;
  this->pin_inb = pin_inb;
  this->pin_pwm = pin_pwm;
  this->speed = 0;
  this->status = MyDC::STATUS_STOPPED;

  pinMode(this->pin_ina, OUTPUT);
  pinMode(this->pin_inb, OUTPUT);
  if (this->pin_pwm > 0) {
    pinMode(this->pin_pwm, OUTPUT);
  }
}

void MyDC::setSpeed(unsigned int speed){
  this->speed = speed;
  if (this->pin_pwm > 0) {
    analogWrite(this->pin_pwm, speed);
  } else {
    switch (this->status) {
      case MyDC::STATUS_FORWARD:
        analogWrite(this->pin_ina, speed);
        break;
      case MyDC::STATUS_REVERSE:
        analogWrite(this->pin_inb, speed);
        break;
    }
  }
}

unsigned int MyDC::getSpeed(){
  return this->speed;
}

char MyDC::getStatus(){
  return this->status;
}

void MyDC::forward(){
  if (this->pin_pwm > 0) {
    digitalWrite(this->pin_ina, HIGH);
    digitalWrite(this->pin_inb, LOW);
  } else {
    analogWrite(this->pin_ina, this->speed);
    analogWrite(this->pin_inb, 0);
  }

  this->status = MyDC::STATUS_FORWARD;
}

void MyDC::forward(unsigned int speed){
  this->setSpeed(speed);
  this->forward();
}

void MyDC::reverse(){
  if (this->pin_pwm > 0) {
    digitalWrite(this->pin_ina, LOW);
    digitalWrite(this->pin_inb, HIGH);
  } else {
    analogWrite(this->pin_ina, 0);
    analogWrite(this->pin_inb, this->speed);
  }

  this->status = MyDC::STATUS_REVERSE;
}

void MyDC::reverse(unsigned int speed){
  this->setSpeed(speed);
  this->reverse();
}

void MyDC::stop(){
  digitalWrite(this->pin_ina, LOW);
  digitalWrite(this->pin_inb, LOW);

  this->status = MyDC::STATUS_STOPPED;
}
