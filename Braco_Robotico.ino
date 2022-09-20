#define joystick1X A0
#define joystick1Y A1
#include <Servo.h>

Servo motorBase;  // create servo object to control a servo
int pos = 90;    // variable to store the servo position

void setup() {
  motorBase.attach(9);
  pinMode (joystick1X, INPUT);
  motorBase.write(pos);
}

void loop() {
  int posX = analogRead(joystick1X);
  posX = map(posX, 0, 1023, 0, 180);
  motorBase.write(posX);
  delay(100);

}
