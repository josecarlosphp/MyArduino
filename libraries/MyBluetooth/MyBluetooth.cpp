/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBluetooth.h"

MyBluetooth::MyBluetooth(
  unsigned int serial,
  unsigned int pin_vcc = 0,
  unsigned int pin_gnd = 0
  ) : powerPins(pin_vcc, pin_gnd) {
  this->serial = serial;
}

bool MyBluetooth::available(){
  switch(this->serial){
    case 0:
      return Serial.available();
    case 1:
      return Serial1.available();
    case 2:
      return Serial2.available();
    case 3:
      return Serial3.available();
  }

  return false;
}

int MyBluetooth::read(){
  switch(this->serial){
    case 0:
      return Serial.read();
    case 1:
      return Serial1.read();
    case 2:
      return Serial2.read();
    case 3:
      return Serial3.read();
  }

  return -1;
}
