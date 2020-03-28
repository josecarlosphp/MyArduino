/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyBluetooth_h
#define MyBluetooth_h

#include "Arduino.h"

class MyBluetooth
{
  private:
    unsigned int serial;

  public:
    MyBluetooth(
      unsigned int serial,
      unsigned int pin_vcc = 0,
      unsigned int pin_gnd = 0
      );

    bool available();

    int read();
};

#endif
