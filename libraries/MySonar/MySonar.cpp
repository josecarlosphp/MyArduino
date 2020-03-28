/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#include "MySonar.h"

MySonar::MySonar(
  unsigned int pin_trigger,
  unsigned int pin_sensor
  ) : MySonar(pin_trigger, pin_sensor, 5000, 0, 0){
}

MySonar::MySonar(
  unsigned int pin_trigger,
  unsigned int pin_sensor,
  unsigned int maxDist
  ) : MySonar(pin_trigger, pin_sensor, maxDist, 0, 0){
}

MySonar::MySonar(
  unsigned int pin_trigger,
  unsigned int pin_sensor,
  unsigned int maxDist,
  unsigned int pin_vcc
  ) : MySonar(pin_trigger, pin_sensor, maxDist, pin_vcc, 0){
}

MySonar::MySonar(
  unsigned int pin_trigger,
  unsigned int pin_sensor,
  unsigned int maxDist,
  unsigned int pin_vcc,
  unsigned int pin_gnd
  ) : NewPing(pin_trigger, pin_sensor, maxDist){
  if(pin_vcc > 0){
	pinMode(pin_vcc, OUTPUT);
	digitalWrite(pin_vcc, HIGH);
  }
  if(pin_gnd > 0){
	pinMode(pin_gnd, OUTPUT);
	digitalWrite(pin_gnd, LOW);
  }
}

int MySonar::GetDist(unsigned int unit = MySonar::UNIT_CENTIMETRES){
  unsigned int echoTime = this->ping_median();
  //unsigned int echoTime = max(this->newPing.ping(), this->newPing.ping());

  return unit == MySonar::UNIT_INCHES ? this->convert_in(echoTime) : this->convert_cm(echoTime);
}
