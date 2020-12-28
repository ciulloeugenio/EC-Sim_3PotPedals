
#include <Joystick.h>

int Acceleratore = 0;
int Freno = 0;
int Frizione = 0;
const int ZonainferioreAcceleratore = 0;
const int ZonasuperioreAcceleratore = 1023;
const int ZonainferioreFreno = 0;
const int ZonasuperioreFreno = 1023;
const int ZonainferioreFrizione = 0;
const int ZonasuperioreFrizione = 1023;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  0, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  true, true, true,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  Joystick.begin();
  Joystick.setRxAxisRange(ZonainferioreAcceleratore, ZonasuperioreAcceleratore);
  Joystick.setRyAxisRange(ZonainferioreFreno, ZonasuperioreFreno);
  Joystick.setRzAxisRange(ZonainferioreFrizione, ZonasuperioreFrizione);
 // Serial.begin(9600);
    }

void loop() {
  Acceleratore = analogRead(A0);
  Freno = analogRead(A1);
  Frizione = analogRead(A2);
  Joystick.setRxAxis(Acceleratore);
  Joystick.setRyAxis(Freno);
  Joystick.setRzAxis(Frizione);
 // Serial.print("Acceleratore : \t");
//  Serial.print(Acceleratore);
//  Serial.print("\t \t Freno: \t");
//  Serial.print(Freno);
//  Serial.print("\t Frizione : \t");
//  Serial.println(Frizione);  
  delay(5);
}
