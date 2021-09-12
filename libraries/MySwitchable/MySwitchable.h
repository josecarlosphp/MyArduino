/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MySwitchable_h
#define MySwitchable_h

#include "Arduino.h"

class MySwitchable
{
  private:
    unsigned int pin_vcc;
    unsigned int pin_gnd;
    bool on;

  public:
    MySwitchable(
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );
    MySwitchable(
      unsigned int pin_vcc,
      unsigned int pin_gnd,
      bool on
      );
};

#endif
