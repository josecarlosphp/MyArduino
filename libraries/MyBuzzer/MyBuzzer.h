/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyBuzzer_h
#define MyBuzzer_h

#include "Arduino.h"

class MyBuzzer
{
  private:
    unsigned int pin_vol;

  public:
    MyBuzzer(
      unsigned int pin_vol,
      unsigned int pin_gnd = 0
      );

    void Buzz(int d = 5);

    void BuzzMulti(int n = 10, int d = 5);

    void Tone(int toneM, long duration, int rest_count = 50);
};

#endif
