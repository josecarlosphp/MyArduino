/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyRTC_h
#define MyRTC_h

#include <MyPowerPins.h>
#include <virtuabotixRTC.h>

class MyRTC
{
  private:
    MyPowerPins powerPins;
    virtuabotixRTC vbRTC;

  public:
    MyRTC(
      uint8_t pin_clk,
      uint8_t pin_dat,
      uint8_t pin_rst
      );
    MyRTC(
      uint8_t pin_clk,
      uint8_t pin_dat,
      uint8_t pin_rst,
      unsigned int pin_vcc
      );
    MyRTC(
      uint8_t pin_clk,
      uint8_t pin_dat,
      uint8_t pin_rst,
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );

    void setTime(
      uint8_t seconds,
      uint8_t minutes,
      uint8_t hours,
      uint8_t dayofweek,
      uint8_t dayofmonth,
      uint8_t month,
      int year
      );
    void setDS1302Time(
      uint8_t seconds,
      uint8_t minutes,
      uint8_t hours,
      uint8_t dayofweek,
      uint8_t dayofmonth,
      uint8_t month,
      int year
      );
    void updateTime(
      );
    String getDatetime(
      );

    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t dayofweek;
    uint8_t dayofmonth;
    uint8_t month;
    int year;
};

#endif
