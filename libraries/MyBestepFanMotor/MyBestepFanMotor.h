/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyBestepFanMotor_h
#define MyBestepFanMotor_h

#include <MyPowerPins.h>
#include <MyDC.h>

class MyBestepFanMotor
{
  private:
    MyPowerPins powerPins;
    MyDC motor;

  public:
    MyBestepFanMotor(
      unsigned int pin_ina,
      unsigned int pin_inb,
      unsigned int pin_vcc = 0,
      unsigned int pin_gnd = 0
      );

    void forward(unsigned int speed = 255);

    void reverse(unsigned int speed = 255);

    void stop();
};

#endif
