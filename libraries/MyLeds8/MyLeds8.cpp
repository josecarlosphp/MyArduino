/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyLeds8.h"

MyLeds8::MyLeds8(
  unsigned int pin_led1,
  unsigned int pin_led2,
  unsigned int pin_led3,
  unsigned int pin_led4,
  unsigned int pin_led5,
  unsigned int pin_led6,
  unsigned int pin_led7,
  unsigned int pin_led8,
  unsigned int pin_vcc = 0
  ){
  this->leds[0] = pin_led1;
  this->leds[1] = pin_led2;
  this->leds[2] = pin_led3;
  this->leds[3] = pin_led4;
  this->leds[4] = pin_led5;
  this->leds[5] = pin_led6;
  this->leds[6] = pin_led7;
  this->leds[7] = pin_led8;

  for(int c=0; c<8; c++){
	pinMode(this->leds[c], OUTPUT);
	digitalWrite(this->leds[c], HIGH);
  }

  if(pin_vcc > 0){
	pinMode(this->leds[pin_vcc], OUTPUT);
	digitalWrite(this->leds[pin_vcc], HIGH);
  }
}

void MyLeds8::Step(){
  if(this->on){
	unsigned long m = millis();
	if(m - this->leds_m >= this->leds_interval){
	  int i = this->leds_i;

	  if(this->leds_s){
		this->leds_i++;
		if(this->leds_i > 7){
		  this->leds_i = 6;
		  this->leds_s = false;
		}
	  }else{
		this->leds_i--;
		if(this->leds_i < 0){
		  this->leds_i = 1;
		  this->leds_s = true;
		}
	  }

	  digitalWrite(this->leds[i], HIGH);
	  digitalWrite(this->leds[this->leds_i], LOW);

	  this->leds_m = m;
	}
  }
}

void MyLeds8::On(bool on = true){
  this->on = on;

  if(!this->on){
	for(int c=0; c<8; c++){
	  digitalWrite(this->leds[c], HIGH);
	}
  }
}

void MyLeds8::Off(){
  this->On(false);
}

void MyLeds8::Toggle(){
  this->On(!this->on);
}
