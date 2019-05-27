#include <VirtualWire.h>

int i1 = 3;
int o1 = 4;
int i2 = 6;
int o2 = 5;
int t = 2;

void setup()
{
    vw_set_rx_pin(t);
    vw_setup(4000);  // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
    Serial.begin(9600);
    pinMode(i1, OUTPUT);
    pinMode(i2, OUTPUT);
    pinMode(o1, OUTPUT);
    pinMode(o2, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
  }

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    //digitalWrite(13, 1);
    if (vw_get_message(buf, &buflen)) // Non-blocking
    { 
      Serial.println(buf[0]);
      //Serial.println("yes");
      char x = buf[0];
      //if(x != '6')
      //Serial.println(x);
      //Serial.println(y);
      //if(x == '1')Serial.println("yea");
      
      if(x == '1'){
        digitalWrite(i1, 1);
        digitalWrite(i2, 1);
        digitalWrite(o1, 0);
        digitalWrite(o2, 0);}
      else if(x == '3'){
        digitalWrite(i1, 0);
        digitalWrite(i2, 0);
        digitalWrite(o1, 1);
        digitalWrite(o2, 1);}
      else if(x == '4'){
        digitalWrite(i1, 1);
        digitalWrite(i2, 0);
        digitalWrite(o1, 0);
        digitalWrite(o2, 1);}
      else if(x == '5'){
        digitalWrite(i1, 0);
        digitalWrite(i2, 1);
        digitalWrite(o1, 1);
        digitalWrite(o2, 0);}
      else{
        digitalWrite(i1, 0);
        digitalWrite(i2, 0);
        digitalWrite(o1, 0);
        digitalWrite(o2, 0);}
        
      }
}
 
