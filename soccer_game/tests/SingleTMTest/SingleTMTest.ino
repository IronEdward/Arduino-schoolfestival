#include <VirtualWire.h>

int p1 = A0;
int p2 = A1;

const int transmit_pin = 12;
const int receive_pin = 2;
const int transmit_en_pin = 3;

char msg[2];
char *test = "1";
void setup()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_setup(2000);       // Bits per sec
    //Serial.begin(9600);
}
int p1r, p2r;
void loop()
{
  p1r = analogRead(p1);
  p2r = analogRead(p2);
  if(p1r > 700)p1r = 3;
  else if(p1r < 300)p1r  =1;
  else p1r = 2;
  if(p2r > 700)p2r = 3;
  else if(p2r < 300)p2r  =1;
  else p2r = 2;
  String a = (String)p1r + (String)p2r;
  a.toCharArray(msg, 4);
  //Serial.println(msg);
  //Serial.print("    ");
  //Serial.println(p2r);
  //vw_send((uint8_t *)msg, 7);
  vw_send((uint8_t *)test, 8);
  vw_wait_tx(); // Wait until the whole message is gone
}
