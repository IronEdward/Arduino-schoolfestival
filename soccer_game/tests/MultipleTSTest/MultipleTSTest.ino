/*
サッカーゲーム六個バージョン。まだテストしていない。うまく行かない所があったらまた直す。
*/

#include <VirtualWire.h>

int p[6][2] = {{A0, A1}, {A2, A3}, {A4, A5}, {A8, A9}, {A10, A11}, {A12, A13}};
char pv[6] = {'0'};
const int transmit_pin = 12;
void setup()
{
    //Serial.begin(9600);
    vw_set_tx_pin(transmit_pin);
    vw_setup(4000);
}

void loop()
{
  for(int i = 0; i < 6; i++){
    int buf1 = analogRead(p[i][0]);
    int buf2 = analogRead(p[i][1]);
    pv[i] = buf1>=800?'1':(buf1<=400?'2':(buf2>=800?'3':buf2<=400?'4':'5'));    //上か下か左か右か止まるを読む
  }
  //Serial.println(pv[3]);
  vw_send((uint8_t *)pv, sizeof(pv));
  vw_wait_tx(); // Wait until the whole message is gone
}
