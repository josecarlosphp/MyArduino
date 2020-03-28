/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MyBuzzer.h"

MyBuzzer::MyBuzzer(
  unsigned int pin_vol,
  unsigned int pin_gnd = 0
  ){
  pinMode(pin_vol, OUTPUT);
  digitalWrite(pin_vol, LOW);

  if(pin_gnd > 0){
    pinMode(pin_gnd, OUTPUT);
    digitalWrite(pin_gnd, LOW);
  }

  this->pin_vol = pin_vol;
}

void MyBuzzer::Buzz(int d = 5){
  digitalWrite(this->pin_vol, HIGH);
  delay(d);
  digitalWrite(this->pin_vol, LOW);
  delay(d);
}

void MyBuzzer::BuzzMulti(int n = 10, int d = 5){
  for(int c=0; c<n; c++){
    this->Buzz(d);
  }
}

void MyBuzzer::Tone(int toneM, long duration, int rest_count = 50){
  long elapsed_time = 0;
  if(toneM > 0){
    while(elapsed_time < duration){
      digitalWrite(this->pin_vol, HIGH);
      delayMicroseconds(toneM / 2);

      digitalWrite(this->pin_vol, LOW);
      delayMicroseconds(toneM / 2);

      elapsed_time += (toneM);
    }
  }else{
    for(int j=0; j<rest_count; j++){
      delayMicroseconds(duration);
    }
  }
}
