/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyTM1637Display_h
#define MyTM1637Display_h

#include <MyPowerPins.h>
#include <TM1637Display.h>

class MyTM1637Display : public TM1637Display
{
  private:
      MyPowerPins powerPins;

  public:
    MyTM1637Display(
      unsigned int pin_clk,
      unsigned int pin_dio
      );
    MyTM1637Display(
      unsigned int pin_clk,
      unsigned int pin_dio,
      unsigned int pin_vcc
      );
    MyTM1637Display(
      unsigned int pin_trigger,
      unsigned int pin_sensor,
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );

    bool ShowTime(String time, bool showDots = true);
};

#endif
