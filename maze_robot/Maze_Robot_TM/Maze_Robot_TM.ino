#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
int ud = A0, lr = A1, ud_v, lr_v;
char v;
const byte rxAddr[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();
}

void loop()
{
  ud_v = analogRead(ud);
  lr_v = analogRead(lr);
  Serial.println(lr_v);
  v = ud_v>600?'1':(ud_v<400?'2':(lr_v>600?'4':(lr_v<400?'3':'5')));
  //Serial.println(v);
  radio.write(&v, sizeof(v));
}
