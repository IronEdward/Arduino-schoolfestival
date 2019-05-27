#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
int i1 = 2, i2 = 3, i3 = 5, i4 = 6;
const byte rxAddr[6] = "00001";
char text[2];

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
}

void motor(int a, int b, int c, int d){
  digitalWrite(i1, a);
  digitalWrite(i2, b);
  digitalWrite(i3, c);
  digitalWrite(i4, d);
}

void loop()
{
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    char v1 = text[0];
    char v2 = text[1];

    int l1v, l2v, r1v, r2v;
    switch(v1){
    case '1':
      l1v = 1;
      l2v = 0;
      break;
    case '2':
      l1v = 0;
      l2v = 1;
      break;
    default:
      l1v = 0;
      l2v = 0;
      break;
    }
    switch(v2){
    case '1':
      r1v = 1;
      r2v = 0;
      break;
    case '2':
      r1v = 0;
      r2v = 1;
      break;
    default:
      r1v = 0;
      r2v = 0;
      break;
    }
    Serial.println(text[1]);
    motor(l1v, l2v, r1v, r2v);
  }
}
