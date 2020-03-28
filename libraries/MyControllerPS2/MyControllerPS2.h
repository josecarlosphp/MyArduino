/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyControllerPS2_h
#define MyControllerPS2_h

#include <PS2X_lib.h>  //for v1.6

class MyControllerPS2 : public PS2X
{
  public:
    MyControllerPS2(
      int pin_data,
      int pin_command,
      int pin_vibration,
      int pin_gnd,
      int pin_5v,
      int pin_attention,
      int pin_clock,
      int pin_void,
      int pin_acknowledge,
      bool pressures = true,
      bool rumble = true
      );

    void read();
};

#endif
