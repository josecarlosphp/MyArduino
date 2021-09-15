/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyL9110_h
#define MyL9110_h

#include <MyPowerPins.h>
#include <MyDC.h>

class MyL9110
{
  private:
    MyPowerPins powerPins;

  public:
    MyDC motorA;
    MyDC motorB;

    MyL9110(
      unsigned int pin_Aina,
      unsigned int pin_Ainb,
      unsigned int pin_Bina,
      unsigned int pin_Binb,
      unsigned int pin_vcc = 0,
      unsigned int pin_gnd = 0
      );

    void forward(unsigned int speed = 255);

    void reverse(unsigned int speed = 255);

    void stop();
};

#endif
