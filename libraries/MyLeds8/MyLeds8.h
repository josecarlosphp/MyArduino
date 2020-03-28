/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyLeds8_h
#define MyLeds8_h

#include "Arduino.h"

class MyLeds8
{
  private:
    unsigned int leds[8];
    int leds_i = 7;
    unsigned long leds_m = 0;
    unsigned int leds_interval = 100;
    bool leds_s = true;
    bool on = false;

  public:
    MyLeds8(
      unsigned int pin_led1,
      unsigned int pin_led2,
      unsigned int pin_led3,
      unsigned int pin_led4,
      unsigned int pin_led5,
      unsigned int pin_led6,
      unsigned int pin_led7,
      unsigned int pin_led8,
      unsigned int pin_vcc = 0
      );

    void Step();

    void On(bool on = true);

    void Off();

    void Toggle();
};

#endif
