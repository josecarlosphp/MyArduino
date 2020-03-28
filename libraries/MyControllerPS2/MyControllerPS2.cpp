/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyControllerPS2.h"

MyControllerPS2::MyControllerPS2(
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
  ) : PS2X(){
  pinMode(pin_gnd, OUTPUT);
  digitalWrite(pin_gnd, LOW);
  pinMode(pin_5v, OUTPUT);
  digitalWrite(pin_5v, HIGH);

  //delay(500);

  this->config_gamepad(
	pin_clock,
	pin_command,
	pin_attention,
	pin_data,
	pressures,
	rumble
	);
}

void MyControllerPS2::read(){
  this->read_gamepad(); //Rumble? read_gamepad(small motor on/off, larger motor strenght from 0-255)
}


/* AYUDA
//https://create.arduino.cc/projecthub/electropeak/how-to-interface-ps2-wireless-controller-w-arduino-a0a813

ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed

if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
     Serial.println("Start is being held");
if(ps2x.Button(PSB_SELECT))
     Serial.println("Select is being held");
     
     
 if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
   Serial.print("Up held this hard: ");
   Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
  }
  if(ps2x.Button(PSB_PAD_RIGHT)){
   Serial.print("Right held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
  }
  if(ps2x.Button(PSB_PAD_LEFT)){
   Serial.print("LEFT held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
  }
  if(ps2x.Button(PSB_PAD_DOWN)){
   Serial.print("DOWN held this hard: ");
 Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
  }   


  vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on 
                                          //how hard you press the blue (X) button    

if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
{   
    if(ps2x.Button(PSB_L3))
     Serial.println("L3 pressed");
    if(ps2x.Button(PSB_R3))
     Serial.println("R3 pressed");
    if(ps2x.Button(PSB_L2))
     Serial.println("L2 pressed");
    if(ps2x.Button(PSB_R2))
     Serial.println("R2 pressed");
    if(ps2x.Button(PSB_GREEN))
     Serial.println("Triangle pressed");
     
}   
     

if(ps2x.ButtonPressed(PSB_RED))             //will be TRUE if button was JUST pressed
     Serial.println("Circle just pressed");
     
if(ps2x.ButtonReleased(PSB_PINK))             //will be TRUE if button was JUST released
     Serial.println("Square just released");     

if(ps2x.NewButtonState(PSB_BLUE))            //will be TRUE if button was JUST pressed OR released
     Serial.println("X just changed");    


if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) // print stick values if either is TRUE
{
    Serial.print("Stick Values:");
    Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC); 
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC); 
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC); 
} 
*/
