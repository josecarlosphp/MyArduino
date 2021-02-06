/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyBinarySensor_h
#define MyBinarySensor_h

#include <MyPowerPins.h>

class MyBinarySensor
{
  private:
    MyPowerPins powerPins;
    unsigned int pin_out;

  public:
    MyBinarySensor(
      unsigned int pin_out
      );
    MyBinarySensor(
      unsigned int pin_out,
      unsigned int pin_vcc
      );
    MyBinarySensor(
      unsigned int pin_out,
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );

    bool Read();
};

#endif
