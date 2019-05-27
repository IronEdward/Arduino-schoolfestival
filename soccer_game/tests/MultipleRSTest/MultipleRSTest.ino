/*
一個ずつのサッカーゲーム。それぞれ読む所が違うからまた直します。
*/
#include <VirtualWire.h>

int i1 = 2, i2 = 5, i3 = 3, i4 = 6;
int trans = 12;
int key = 3;                               //どのジョイスティックの値を読むか判断する。(値は0～５)
char v;                               //上下、左右の値を読む。
char check;                                //こいつを見て、モーターを動かす。

void motor(int a, int b, int c, int d){
  digitalWrite(i1, a);
  digitalWrite(i2, b);
  digitalWrite(i3, c);
  digitalWrite(i4, d);
}

void setup()
{
    vw_set_rx_pin(trans);
    vw_setup(4000);
    vw_rx_start();
    pinMode(i1, OUTPUT);                   //ここら辺効率悪いな…まいっかw
    pinMode(i2, OUTPUT);
    pinMode(i3, OUTPUT);
    pinMode(i4, OUTPUT);
    //Serial.begin(9600);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen))      //信号が入ってきたら…
    {
      v = buf[0 + key];
      //Serial.println(v);
      //check = v=='1'?'1':(ud<1?2:(lr>1?3:4)); //もし上下信号があればそれを優先、もしなければ左右の信号を見る。
      
        if(v=='1')motor(1, 1, 0, 0);
        else if(v=='2')motor(0, 0, 1, 1);
        else if(v=='3')motor(1, 0, 0, 1);
        else if(v=='4')motor(0, 1, 1, 0);
        else motor(1, 1, 1, 1);
      
      /*
      switch(v){
        case '1':
        motor(1, 1, 0, 0);
        break;
        case '2':
        motor(0, 0, 1, 1);
        break;
        case '3':
        motor(1, 0, 0, 1);
        break;
        case '4':
        motor(0, 1, 1, 0);
        break;
        default:
        motor(0, 0, 0, 0);
        break;
    }
    */
  }
}
