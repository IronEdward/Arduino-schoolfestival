#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte rxAddr[6] = "00001";
int i1=2,i2=3,i3=4,i4=5;
char text[2];
void setup()
{
  //Serial.begin(9600);
  pinMode(i1, OUTPUT);
  pinMode(i2, OUTPUT);
  pinMode(i3, OUTPUT);
  pinMode(i4, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.println(text[0]);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
}

void setMotor(int v1,int v2,int v3,int v4){
  digitalWrite(i1,v1);
  digitalWrite(i2,v2);
  digitalWrite(i3,v3);
  digitalWrite(i4,v4);
}

void loop()
{
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    digitalWrite(6, 1);
    Serial.println(text[0]);
    switch(text[0]){
    case '1':
      //Serial.println("1");
      setMotor(1,0,1,0);
      break;
    case '2':
      //Serial.println("2");
      setMotor(0,1,0,1);
      break;
    case '3':
      //Serial.println("3");
      setMotor(1,0,0,1);
      break;
    case '4':
      //Serial.println("4");
      setMotor(0,1,1,0);
      break;
    default:
      //Serial.println("Stop");
      setMotor(0,0,0,0);
      break;
    }
  }
  //else Serial.println("No Signal");
}
