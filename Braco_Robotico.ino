#include <Servo.h>

// Mapeamento dos Joysticks
#define joystick1X A0
#define joystick1Y A1
#define joystick2X A2
#define joystick2Y A3

//definição dos servo motores
Servo motorBase, motorBraco1, motorBraco2, motorGarra;  // create servo object to control a servo
int iniciaMotor = 90;    // variable to store the servo position

//Funções movimento motores
void moverBase(){
  int posX = analogRead(joystick1X);
  posX = map(posX, 0, 1023, 0, 180);
  motorBase.write(posX);
}
void moverBraco1(){
  int posY = analogRead(joystick1Y);
  posY = map(posY, 0, 1023, 40, 90);
  motorBraco1.write(posY);
}
void moverBraco2(){
  int posX = analogRead(joystick2X);
  posX = map(posX, 0, 1023, 45, 110);
  motorBraco2.write(posX);
}
void moverGarra(){
  int posY = analogRead(joystick2Y);
  posY = map(posY, 0, 1023, 10, 180);
  motorGarra.write(posY);
}

void setup() {
  motorBase.attach(5);
  motorBraco1.attach(6);
  motorBraco2.attach(9);
  motorGarra.attach(10);

  motorBase.write(iniciaMotor);
  motorBraco1.write(iniciaMotor);
  motorBraco2.write(iniciaMotor);
  motorGarra.write(iniciaMotor);

  pinMode (joystick1X, INPUT);
  pinMode (joystick1Y, INPUT);
  pinMode (joystick2X, INPUT);
  pinMode (joystick2Y, INPUT);

  
}

void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();
  delay(100);

}
