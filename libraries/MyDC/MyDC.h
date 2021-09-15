/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyDC_h
#define MyDC_h

#include "Arduino.h"

class MyDC
{
  private:
    unsigned int pin_ina;
    unsigned int pin_inb;

  public:
    MyDC(
      unsigned int pin_ina,
      unsigned int pin_inb
      );

    void forward(unsigned int speed = 255);

    void reverse(unsigned int speed = 255);

    void stop();
};

#endif
