/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyRTC.h"

MyRTC::MyRTC(
  uint8_t pin_clk,
  uint8_t pin_dat,
  uint8_t pin_rst
  ) : MyRTC(pin_clk, pin_dat, pin_rst, 0, 0){
}

MyRTC::MyRTC(
  uint8_t pin_clk,
  uint8_t pin_dat,
  uint8_t pin_rst,
  unsigned int pin_vcc
  ) : MyRTC(pin_clk, pin_dat, pin_rst, pin_vcc, 0){
}

MyRTC::MyRTC(
  uint8_t pin_clk,
  uint8_t pin_dat,
  uint8_t pin_rst,
  unsigned int pin_vcc,
  unsigned int pin_gnd
  )
  :
  powerPins(pin_vcc, pin_gnd),
  vbRTC(pin_clk, pin_dat, pin_rst) {
}

void MyRTC::setTime(
  uint8_t seconds,
  uint8_t minutes,
  uint8_t hours,
  uint8_t dayofweek,
  uint8_t dayofmonth,
  uint8_t month,
  int year
  ) {
  setDS1302Time(seconds, minutes, hours, dayofweek, dayofmonth, month, year);
}

void MyRTC::setDS1302Time(
  uint8_t seconds,
  uint8_t minutes,
  uint8_t hours,
  uint8_t dayofweek,
  uint8_t dayofmonth,
  uint8_t month,
  int year
  ) {
  vbRTC.setDS1302Time(seconds, minutes, hours, dayofweek, dayofmonth, month, year);
}

void MyRTC::updateTime() {
  vbRTC.updateTime();

  seconds = vbRTC.seconds;
  minutes = vbRTC.minutes;
  hours = vbRTC.hours;
  dayofweek = vbRTC.dayofweek;
  dayofmonth = vbRTC.dayofmonth;
  month = vbRTC.month;
  year = vbRTC.year;
}

String MyRTC::getDatetime() {
  updateTime();

  char buffer[40] = "";
  char* formato = "%04d-%02d-%02d %02d:%02d:%02d";
  sprintf(buffer, formato, year, month, dayofmonth, hours, minutes, seconds);

  return buffer;
}