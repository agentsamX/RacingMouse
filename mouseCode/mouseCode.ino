// By Sam Canonaco
// Based on examples by Matthew Heironimus
//-----------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  
  2, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  true, true, true);  // No accelerator, brake, or steering

int LMB_PIN = 2;
int RMB_PIN = 3;

int LMB_LVALUE= 0;
int RMB_LVALUE= 0;

int LMB_APIN = A0;
int RMB_APIN = A1;
int STEERING_APIN=A2;

int LMB_AVALUE = 0;
int RMB_AVALUE = 0;
int STEERING_AVALUE = 0;

void setup() {
  // Initialize Button Pins
  pinMode(LMB_PIN, INPUT_PULLUP);
  pinMode(RMB_PIN, INPUT_PULLUP);
 
  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setAcceleratorRange(-512,512);
  Joystick.setBrakeRange(-512,512);
  Joystick.setSteeringRange(-512,512);

}

void loop() {

  // Read digital pin values
\
  int state = !digitalRead(LMB_PIN);
  if (state != LMB_LVALUE)
  {
    Joystick.setButton(0, state);
    LMB_LVALUE = state;
  }

  state = !digitalRead(RMB_PIN);
   if (state != RMB_LVALUE)
  {
    Joystick.setButton(1, state);
    RMB_LVALUE = state;
  }

  //Read analog pin values
  LMB_AVALUE = analogRead(LMB_APIN);
  RMB_AVALUE = analogRead(RMB_APIN);
  STEERING_AVALUE = analogRead(STEERING_APIN);

  Joystick.setAccelerator(LMB_AVALUE);
  Joystick.setBrake(RMB_AVALUE);
  Joystick.setSteering(STEERING_AVALUE);
  
  delay(10);
}

