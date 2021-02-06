/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MySonar_h
#define MySonar_h

#include <NewPing.h>

class MySonar : public NewPing
{
  private:
    static const unsigned int UNIT_INCHES = 1;
    static const unsigned int UNIT_CENTIMETRES = 0;

  public:
    MySonar(
      unsigned int pin_trigger,
      unsigned int pin_sensor
      );
    MySonar(
      unsigned int pin_trigger,
      unsigned int pin_sensor,
      unsigned int maxDist
      );
    MySonar(
      unsigned int pin_trigger,
      unsigned int pin_sensor,
      unsigned int maxDist,
      unsigned int pin_vcc
      );
    MySonar(
      unsigned int pin_trigger,
      unsigned int pin_sensor,
      unsigned int maxDist,
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );

    int GetDist(unsigned int unit = MySonar::UNIT_CENTIMETRES);
};

#endif
