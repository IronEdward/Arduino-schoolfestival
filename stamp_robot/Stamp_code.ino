#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int servonum = 0;
int buttonPin = 3;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}


void loop() {
bool button = false;
  button = digitalRead(buttonPin);
  pwm.setPWM(0, 0, 300);
  pwm.setPWM(1, 0, 250);
  if(button == 1) counter += 1;
  if(counter >3){
    counter = 0;
      pwm.setPWM(1, 0, 400);
      delay(500);
      pwm.setPWM(0, 0, 500);
      delay(500);
      pwm.setPWM(1, 0, 250);
      delay(2
      :000);
      pwm.setPWM(1, 0, 400);
      delay(500);
      pwm.setPWM(0, 0, 300);
      delay(500);
      pwm.setPWM(1, 0, 250);
  }
}
