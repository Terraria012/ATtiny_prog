#include "SimpleYMF825.h"
#include <Arduino.h>

SimpleYMF825 YMF825;

uint8_t channel = 1;
uint8_t channel1 = 0;
uint8_t ch = 2;
uint8_t c = 3;
int x = 220;
// int y = 150;

void setup()
{
    YMF825.begin(IOVDD_5V);     // for 5V McU

    //YMF825.begin(IOVdd_3V3); // for 3.3V McU
  for(int i=0;i<4;i++){
    YMF825.setTone( i, GRAND_PIANO );
  }

    YMF825.setMasterVolume(32);
    
    for(int ch=0;ch<4;ch++){
        YMF825.setVolume(ch, 25);
    }               
  }




void loop()
{
YMF825.keyon(channel, 0x45);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x44);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x44);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x45);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x43);
    delay(x/2+x/4);
    YMF825.keyoff(channel);
    delay(x/4);
    YMF825.keyoff(ch);

    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x43);
    delay(x/2);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    delay(x/2);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x42);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x42);
    delay(x/2);
    YMF825.keyoff(channel);
    delay(x/2);
    YMF825.keyoff(ch);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x41);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x41);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x51);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);


    
    
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x44);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(channel, 0x54);
    YMF825.keyon(ch, 0x44);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x5A);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x42);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x42);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x41);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x41);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x43);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x37);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);


  
    YMF825.keyon(channel, 0x45);
    YMF825.keyon(c, 0x40);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(c, 0x48);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(c, 0x44);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x45);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x/2);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    delay(x/2);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x47);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x48);
    YMF825.keyon(c, 0x55);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(c, 0x53);
    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(c, 0x4A);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x51);
    YMF825.keyon(c, 0x4A);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(c, 0x47);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);


    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(c, 0x48);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);
    
    YMF825.keyon(channel, 0x48);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(c, 0x48);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(c, 0x50);
    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(c, 0x47);
    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x54);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x34);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);





    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x4A);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x5A);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(c, 0x52);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(c, 0x52);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(c, 0x55);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x32);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(c, 0x53);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x31);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x58);
    YMF825.keyon(c, 0x53);
    YMF825.keyon(ch, 0x38);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x57);
    YMF825.keyon(ch, 0x47);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x50);
    YMF825.keyon(ch, 0x33);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x53);
    YMF825.keyon(ch, 0x3A);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 0x55);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x35);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x40);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x45);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x48);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 0x50);
    delay(4*x);
    YMF825.keyoff(ch);
  }