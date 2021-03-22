/*
 * José Carlos Cruz Parra
 * https://josecarlosphp.com
 */

#ifndef MyServo_h
#define MyServo_h

#include <MyPowerPins.h>
#include <Servo.h>

class MyServo
{
  private:
    Servo servo;
    unsigned int pin_data;
    MyPowerPins powerPins;

  public:
    unsigned int min_angle;
    unsigned int max_angle;

    MyServo(
      unsigned int pin_data
      );
    MyServo(
      unsigned int pin_data,
      unsigned int min_angle
      );
    MyServo(
      unsigned int pin_data,
      unsigned int min_angle,
      unsigned int max_angle
      );
    MyServo(
      unsigned int pin_data,
      unsigned int min_angle,
      unsigned int max_angle,
      unsigned int pin_vcc
      );
    MyServo(
      unsigned int pin_data,
      unsigned int min_angle,
      unsigned int max_angle,
      unsigned int pin_vcc,
      unsigned int pin_gnd
      );

    void Init();

    void SetRange(unsigned int min_angle, unsigned int max_angle);
    void SetMinAngle(unsigned int min_angle);
    void SetMaxAngle(unsigned int max_angle);

    void TurnDown();
    void TurnDown(unsigned int degrees);
    void TurnUp();
    void TurnUp(unsigned int degrees);
    void Turn(int degrees);
    void TurnTo(unsigned int degrees);
    void TurnTo(unsigned int degrees, unsigned int idelay);

    void attach(unsigned int pin);
    void write(unsigned int angle);
    unsigned int read();
};

#endif
