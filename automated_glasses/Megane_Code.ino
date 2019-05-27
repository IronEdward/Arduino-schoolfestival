#include <Servo.h>

const int buttonPin = 12;    // the number of the pushbutton pin
Servo myservo;

int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int led = 13;
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);

  //Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}

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

  if(ledState){myservo.write(0); digitalWrite(led, HIGH);}
  else{myservo.write(90); digitalWrite(led, LOW);}
    //Serial.println(ledState);
  lastButtonState = reading;
}
