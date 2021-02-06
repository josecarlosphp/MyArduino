/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyTM1637Display.h"

MyTM1637Display::MyTM1637Display(
  unsigned int pin_clk,
  unsigned int pin_dio
  ) : MyTM1637Display(pin_clk, pin_dio, 0, 0){
}

MyTM1637Display::MyTM1637Display(
  unsigned int pin_clk,
  unsigned int pin_dio,
  unsigned int pin_vcc
  ) : MyTM1637Display(pin_clk, pin_dio, pin_vcc, 0){
}

MyTM1637Display::MyTM1637Display(
  unsigned int pin_clk,
  unsigned int pin_dio,
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) : powerPins(pin_vcc, pin_gnd), TM1637Display(pin_clk, pin_dio){
  setBrightness(1, true);
}

bool MyTM1637Display::ShowTime(
  String time,
  bool showDots = true
  ) {
  if(time.length() != 5){
    return false;
  }
  showNumberDecEx(time.substring(0, 2).toInt(), showDots ? 0x40 : 0, true, 2, 0);
  showNumberDecEx(time.substring(3, 5).toInt(), 0, true, 2, 2);

  return true;
}