#include <Servo.h>
#define HalA 31
#define HalB 33
#define Limit 35
#define MotorRel1 23
#define MotorRel2 25
#define MotorRelPWM 2
#define MotorPutar1 27
#define MotorPutar2 29
#define MotorPutarPWM 3
Servo capit1;
Servo capit2;
Servo capit3;
int buka = 180, tutup = 0;
char data;

void setup() {
  capit1.attach(4);
  capit2.attach(5);
  capit3.attach(6);

  pinMode(MotorRel1, OUTPUT);
  pinMode(MotorRel2, OUTPUT);
  pinMode(MotorRelPWM, OUTPUT);
  pinMode(MotorPutar1, OUTPUT);
  pinMode(MotorPutar2, OUTPUT);
  pinMode(MotorPutarPWM, OUTPUT);

  Serial.begin(9600);

  Serial.println("Go to loop");

}

void loop() {
  if (Serial.available() > 0) {
    data = (char) Serial.read();
    Serial.println(data);
  }

  if (data == 'W') capit1.write(buka);
  else if (data == 'w') capit1.write(tutup);
  else if (data == 'U') capit2.write(buka);
  else if (data == 'u') capit2.write(tutup);
  else if (data == 'V') capit3.write(buka);
  else if (data == 'v') capit3.write(tutup);
  else if (data == 'F') putar(1, 0, 120);
  else if (data == 'B') putar(0, 1, 120);
  else if (data == 'R') Rel(1, 0, 120);
  else if (data == 'L') Rel(0, 1, 120);
  else diam();


  }

void Rel(bool pin1, bool pin2, int PWM) {
  digitalWrite(MotorRel1, pin1);
  digitalWrite(MotorRel2, pin2);
  analogWrite(MotorRelPWM, PWM);
}

void putar(bool pin1, bool pin2, int PWM) {
  digitalWrite(MotorPutar1, pin1);
  digitalWrite(MotorPutar2, pin2);
  analogWrite(MotorPutarPWM, PWM);
}

void diam() {
  digitalWrite(MotorPutar1, 0);
  digitalWrite(MotorPutar2, 0);
  analogWrite(MotorPutarPWM, 0);
  digitalWrite(MotorRel1, 0);
  digitalWrite(MotorRel2, 0);
  analogWrite(MotorRelPWM, 0);
}
