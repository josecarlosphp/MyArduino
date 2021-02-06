/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyPowerPins_h
#define MyPowerPins_h

#include "arduino.h"

class MyPowerPins
{
  private:
    unsigned int pin_vcc;
    unsigned int pin_gnd;

  public:
    MyPowerPins(
      );
    MyPowerPins(
      unsigned int pin_vcc
      );
    MyPowerPins(
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );
};

#endif
