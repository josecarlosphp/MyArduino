/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyL9110.h"

MyL9110::MyL9110(
  unsigned int pin_Aina,
  unsigned int pin_Ainb,
  unsigned int pin_Bina,
  unsigned int pin_Binb,
  unsigned int pin_vcc = 0,
  unsigned int pin_gnd = 0
  ) : powerPins(pin_vcc, pin_gnd), motorA(pin_Aina, pin_Ainb), motorB(pin_Bina, pin_Binb) {}

void MyL9110::forward(unsigned int speed){
  this->motorA.forward(speed);
  this->motorB.forward(speed);
}

void MyL9110::reverse(unsigned int speed){
  this->motorA.reverse(speed);
  this->motorB.reverse(speed);
}

void MyL9110::stop(){
  this->motorA.stop();
  this->motorB.stop();
}
