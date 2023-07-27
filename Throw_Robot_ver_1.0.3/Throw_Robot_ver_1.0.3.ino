//#include <Wire.h>
//#define address 0x1E //0011110b, I2C 7bit address of HMC5883
#define mdep1 31
#define mdep2 29
#define mkir1 27
#define mkir2 25
#define mbel1 24
#define mbel2 26
#define mkan1 28
#define mkan2 30
#define pwmdep 5
#define pwmkir 4
#define pwmbel 7
#define pwmkan 6
#define pwmdiam 0
#define setPoint 0
#define kp 17
#define ki 12
#define kd 1
#define kecMax 200
#define kecStandar 180

//set kec


//int kecKanan, kecKiri;

char data;

//int xaxis;
//int e, laste, kecKanan, kecKiri, out, hmm;

void setup() {
  pinMode(mdep1, OUTPUT);
  pinMode(mdep2, OUTPUT);
  pinMode(mkir1, OUTPUT);
  pinMode(mkir2, OUTPUT);
  pinMode(mbel1, OUTPUT);
  pinMode(mbel2, OUTPUT);
  pinMode(mkan1, OUTPUT);
  pinMode(mkan2, OUTPUT);
  pinMode(pwmdep, OUTPUT);
  pinMode(pwmkir, OUTPUT);
  pinMode(pwmbel, OUTPUT);
  pinMode(pwmkan, OUTPUT);
  Serial.begin(9600);
  Serial.println("Go to loop");

  //  Wire.begin();
  //  Wire.beginTransmission(address);
  //  Wire.write(0x02);
  //  Wire.write(0x00);
  //  Wire.endTransmission();
  //
  //  TCCR2B = TCCR2B & 0b11111000 | 0x05;
  //  TCCR4B = TCCR4B & 0b11111000 | 0x05;
}

void gerak(bool modr11, bool modr12, bool modr21, bool modr22, bool modr31, bool modr32, bool modr41, bool modr42, int pwm11, int pwm22, int pwm33, int pwm44) {
  digitalWrite(mdep1, modr11);
  digitalWrite(mdep2, modr12);
  digitalWrite(mkir1, modr21);
  digitalWrite(mkir2, modr22);
  digitalWrite(mbel1, modr31);
  digitalWrite(mbel2, modr32);
  digitalWrite(mkan1, modr41);
  digitalWrite(mkan2, modr42);
  analogWrite(pwmdep, pwm11);
  analogWrite(pwmkir, pwm22);
  analogWrite(pwmbel, pwm33);
  analogWrite(pwmkan, pwm44);
}

void diam() {
  gerak(0, 0, 0, 0, 0, 0, 0, 0, pwmdiam, pwmdiam, pwmdiam, pwmdiam);
}
void loop() {

  if (Serial.available() > 0) {
    data = (char) Serial.read();
    Serial.println(data);
  }

  if (data == 'F') gerak(0, 0, 0, 1, 0, 0, 0, 1, 60, 60, 60, 60);
  else if (data == 'R') gerak(0, 1, 0, 0, 0, 1, 0, 0, 60, 60, 60, 60);
  else if (data == 'L') gerak(1, 0, 0, 0, 1, 0, 0, 0, 60, 60, 60, 60);
  else if (data == 'B') gerak(0, 0, 1, 0, 0, 0, 1, 0, 60, 60, 60, 60);
  else diam();
}
