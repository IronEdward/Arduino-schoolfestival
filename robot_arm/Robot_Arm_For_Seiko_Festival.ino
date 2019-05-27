#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter


int p1 = A1;
int p2 = A2;
int p3 = A3;
int p4 = A6;
int p5 = A7;

int p1v = 0;
int p2v = 0;
int p3v = 0;
int p4v = 0;
int p5v = 0;


uint8_t s1 = 0;
uint8_t s2 = 1;
uint8_t s3 = 2;
uint8_t s4 = 3;
uint8_t s5 = 4;
uint8_t s6 = 5;

//int p = [A1, A2, A3, A6, A7];
//int pv = [0, 0, 0, 0, 0];

int Pmin = 350;
int Pmax = 600;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
  /*
  int i;
  for(i = 0; i < 5; i++){
    pv[i] = analogRead(p[i]);
    pv[i] = map(pv[i], 0, 1023, Pmin, Pmax);
  }
  */
  p1v = analogRead(p1);
  p2v = analogRead(p2);
  p3v = analogRead(p3);
  p4v = analogRead(p4);
  p5v = analogRead(p5);

  p1v = map(p1v, 0, 1023, 200, 550);
  p2v = map(p2v, 0, 1023, 200, 550);
  p3v = map(p3v, 0, 1023, 200, 550);
  p4v = map(p4v, 0, 1023, 200, 550);
  p5v = map(p5v, 0, 1023, 200, 550);

  pwm.setPWM(s1, 0, p1v);
  pwm.setPWM(s2, 0, p2v);
  pwm.setPWM(s3, 0, p2v);
  pwm.setPWM(s4, 0, p3v);
  pwm.setPWM(s5, 0, p4v);
  pwm.setPWM(s6, 0, p5v);
}
