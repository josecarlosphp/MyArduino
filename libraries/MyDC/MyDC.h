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
    unsigned int pin_pwm;
    unsigned int speed;
    char status;

  public:
    static const char STATUS_FORWARD = 'F';
    static const char STATUS_REVERSE = 'R';
    static const char STATUS_STOPPED = 'S';

    MyDC(
      unsigned int pin_ina,
      unsigned int pin_inb
      );
    MyDC(
      unsigned int pin_ina,
      unsigned int pin_inb,
      unsigned int pin_pwm
      );

    void setSpeed(unsigned int speed);
    unsigned int getSpeed();

    char getStatus();

    void forward();
    void forward(unsigned int speed);

    void reverse();
    void reverse(unsigned int speed);

    void stop();
};

#endif
