/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MySwitchable.h"

MySwitchable::MySwitchable(
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) {
  pinMode(pin_vcc, OUTPUT);
  pinMode(pin_gnd, OUTPUT);
  digitalWrite(pin_gnd, LOW);
}

MySwitchable::MySwitchable(
  unsigned int pin_vcc,
  unsigned int pin_gnd,
  bool on
  ) {
  pinMode(pin_vcc, OUTPUT);
  pinMode(pin_gnd, OUTPUT);
  digitalWrite(pin_gnd, LOW);
  this->on = !on;
  this->Toggle();
}

void MySwitchable::On() {
  this->on = true;
  digitalWrite(pin_vcc, HIGH);
}

void MySwitchable::Off() {
  this->on = false;
  digitalWrite(pin_vcc, LOW);
}

bool MySwitchable::Toggle() {
  if (this->on) {
      this->Off();
  } else {
      this->On();
  }

  return this->on;
}