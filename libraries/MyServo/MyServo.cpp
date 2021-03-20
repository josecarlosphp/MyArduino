/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyServo.h"

MyServo::MyServo(
  unsigned int pin_data
  ) : MyServo(pin_data, 0, 180, 0, 0){
}

MyServo::MyServo(
  unsigned int pin_data,
  unsigned int min_angle
  ) : MyServo(pin_data, min_angle, 180, 0, 0){
}

MyServo::MyServo(
  unsigned int pin_data,
  unsigned int min_angle,
  unsigned int max_angle
  ) : MyServo(pin_data, min_angle, max_angle, 0, 0){
}

MyServo::MyServo(
  unsigned int pin_data,
  unsigned int min_angle,
  unsigned int max_angle,
  unsigned int pin_vcc
  ) : MyServo(pin_data, min_angle, max_angle, pin_vcc, 0){
}

MyServo::MyServo(
  unsigned int pin_data,
  unsigned int min_angle,
  unsigned int max_angle,
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) : powerPins(pin_vcc, pin_gnd){
    this->pin_data = pin_data;
    this->SetRange(min_angle, max_angle);
}

void MyServo::Init(){
  this->attach(this->pin_data);
}

void MyServo::SetRange(
  unsigned int min_angle,
  unsigned int max_angle
){
  this->SetMinAngle(min_angle);
  this->SetMaxAngle(max_angle);
}

void MyServo::SetMinAngle(
  unsigned int min_angle
){
    this->min_angle = min_angle;
}

void MyServo::SetMaxAngle(
  unsigned int max_angle
){
    this->max_angle = max_angle;
}

void MyServo::TurnDown(){
    this->TurnDown(1);
}

void MyServo::TurnDown(unsigned int degrees){
    this->Turn(-degrees);
}

void MyServo::TurnUp(){
    this->TurnUp(1);
}

void MyServo::TurnUp(unsigned int degrees){
    this->Turn(degrees);
}

void MyServo::Turn(int degrees){
    this->servo.write(this->servo.read() + degrees);
}

void MyServo::attach(
  unsigned int pin
){
    this->servo.attach(pin);
}

void MyServo::write(
  unsigned int angle
){
    if (angle < this->min_angle) {
        angle = this->min_angle;
    } else if (angle > this->max_angle) {
        angle = this->max_angle;
    }

    this->servo.write(angle);
}

unsigned int MyServo::read(
){
    return this->servo.read();
}