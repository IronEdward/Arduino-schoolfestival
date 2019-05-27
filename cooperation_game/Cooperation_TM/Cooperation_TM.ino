#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte rxAddr[6] = "00001";
char v[2];
int x1= A2, x2 = A0;
int x1val, x2val;

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
  x1val = analogRead(x1);
  x2val = analogRead(x2);
  if(x1val > 650)v[0] = '2';
  else if(x1val < 400)v[0] = '1';
  else v[0] = '0'; 
  
  if(x2val > 650)v[1] = '1';
  else if(x2val < 400)v[1] = '2';
  else v[1] = '0'; 

  Serial.print(v[0]);
  Serial.print("   ");
  Serial.println(v[1]);
  radio.write(&v, sizeof(v));
}
