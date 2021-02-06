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
      unsigned int pin_out,
      unsigned int pin_vcc = 0,
      unsigned int pin_gnd = 0
      );

    int Read();
};

#endif
