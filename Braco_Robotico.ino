#define joystick1X A0
#define joystick1Y A1
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 180;    // variable to store the servo position

void setup() {
  pinMode (joystick1X, INPUT);
  pinMode (joystick1Y, INPUT);
  Serial.begin(9600);

  
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  myservo.write(pos);
  Serial.print(pos);
  Serial.println(" GRAUS");
}

void loop() {
  int x, y;
  x= analogRead( joystick1X );
  y= analogRead( joystick1Y );
  Serial.print(x);
  Serial.print("  ,  ");
  Serial.println(y);

  myservo.write(x);
  delay(100);

}
