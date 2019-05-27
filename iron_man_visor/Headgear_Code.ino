#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600

uint8_t s1 = 0;
uint8_t s2 = 1;
int buttonPin = 3;

int leftmin = 350;
int leftmax = 600;
int rightmin = 600;
int rightmax = 370;

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int led = 13;
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.begin(9600);
}

int button = 0, flag = 0;

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  if(ledState){
      pwm.setPWM(s1, 0, leftmax);
    pwm.setPWM(s2, 0, rightmax);
  
  }
  else{
      pwm.setPWM(s1, 0, leftmin);
    pwm.setPWM(s2, 0, rightmin);
  }
  lastButtonState = reading;

}
