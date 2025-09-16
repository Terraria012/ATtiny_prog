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
    // YMF825.setTone( 4, TNKL_BeLL );
    // YMF825.setTone( 5, NeW_age_Pd );  
        // YMF825.setTone( 6, BRIgHT_PIaNO );
    // YMF825.setTone( 7, VIBes );
    // YMF825.setTone( 8, cHURcH_ORgaN );
    // YMF825.setTone( 9, FLUTE );
    // YMF825.setTone(10, ROcK_ORgaN );
    // YMF825.setTone(11, NYLON_gUITeR );
    // YMF825.setTone(12, SQUARE_LEAD );
    // YMF825.setTone(13, saW_Lead );
    // YMF825.setTone(14, HaRPsIcHORd );
    // YMF825.setTone(15, HaRMONIca );
    
    YMF825.setMasterVolume(32);
    
    for(int ch=0;ch<4;ch++){
        YMF825.setVolume(ch, 25);
    }               
}

void play1(void) {
    YMF825.keyon(c, 0x51);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x54);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x56);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
}

void play2(void) {
    YMF825.keyon(c, 0x4B);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x51);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x54);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
}

 void play3(void) {
    YMF825.keyon(c, 0x49);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x44);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x4B);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x44);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x51);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x44);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x49);
  delay(x/2+x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x44);
  delay(x);
  YMF825.keyoff(c);
 }

  void play4(void) {
  YMF825.keyon(c, 0x4B);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x51);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x+x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x4B);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x);
  YMF825.keyoff(c);
  }

  void play5(void) {
  YMF825.keyon(c, 0x50);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x51);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x56);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x50);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x56);
  delay(x);
  YMF825.keyoff(c);
  }





void loop()
{
  YMF825.keyon(channel1, 0x33);
  play1();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x33);
  play1();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x38);
  play2();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x38);
  play2();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x39);
  play3();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x36);
  play4();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x38);
  play5();
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x38);
  YMF825.keyon(c, 0x54);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyoff(channel1);

  YMF825.keyon(channel1, 0x38);
  YMF825.keyon(c, 0x50);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyoff(channel1);

  YMF825.keyon(c, 0x51);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x50);
  delay(x/2);
  YMF825.keyoff(c);

  YMF825.keyon(channel1, 0x38);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyoff(channel1);

  YMF825.keyon(c, 0x44);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x43);
  delay(x/2);
  YMF825.keyoff(c);


  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x44);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x44);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x4B);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);

  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x49);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x49);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x4B);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x47);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x50);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);





  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x44);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x44);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x4B);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);

  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x49);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x49);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x4B);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x47);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x50);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x40);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);



    YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x5B);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x44);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x41);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x46);
  YMF825.keyon(channel, 0x32);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x42);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x46);
  YMF825.keyon(channel, 0x32);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x32);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x44);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x3B);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);

  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x59);
  YMF825.keyon(c, 0x49);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x46);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x4B);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x46);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x49);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x49);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x49);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x63);
  YMF825.keyon(c, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x64);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x49);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x64);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x4B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x63);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x4B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x4B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x64);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x4B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x66);
  YMF825.keyon(c, 0x60);
  YMF825.keyon(channel, 0x48);
  delay(x+x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x66);
  YMF825.keyon(c, 0x50);
  YMF825.keyon(channel, 0x48);
  delay(x+x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x66);
  YMF825.keyon(c, 0x60);
  YMF825.keyon(channel, 0x48);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x68);
  YMF825.keyon(c, 0x60);
  YMF825.keyon(channel, 0x48);
  delay(4*x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);


    YMF825.keyon(ch, 0x48);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x2B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x4B);
  YMF825.keyon(c, 0x46);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x46);
  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x2B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(c);

  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x33);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x39);
  delay(2*x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x3B);
  delay(2*x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x56);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);

  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x56);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);




  YMF825.keyon(ch, 0x48);
  YMF825.keyon(c, 0x44);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x2B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x4B);
  YMF825.keyon(c, 0x46);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x46);
  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x2B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(c);

  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x3B);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x48);
  YMF825.keyon(c, 0x43);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x33);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x56);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x39);
  delay(2*x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x3B);
  delay(2*x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x41);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(c, 0x48);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x26);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x36);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x31);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x56);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x53);
  YMF825.keyon(c, 0x4B);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(c, 0x51);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);

  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x56);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x58);
  YMF825.keyon(c, 0x54);
  YMF825.keyon(channel, 0x29);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x5B);
  YMF825.keyon(c, 0x56);
  YMF825.keyon(channel, 0x39);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x34);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x60);
  YMF825.keyon(c, 0x53);
  YMF825.keyon(channel, 0x28);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x33);
  delay(x/2);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x63);
  YMF825.keyon(c, 0x58);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyon(channel, 0x38);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x68);
  YMF825.keyon(c, 0x60);
  YMF825.keyon(channel, 0x33);
  delay(x);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);
  YMF825.keyoff(c);

  YMF825.keyon(ch, 0x64);
  YMF825.keyon(channel, 0x28);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x63);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x61);
  YMF825.keyon(channel, 0x33);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x60);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x54);
  YMF825.keyon(channel, 0x38);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x53);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x51);
  YMF825.keyon(channel, 0x33);
  delay(x/2);
  YMF825.keyoff(ch);

  YMF825.keyon(ch, 0x50);
  delay(x/2);
  YMF825.keyoff(channel);
  YMF825.keyoff(ch);


  play1();
  play1();
  play2();
  play2();
  play3();
  play4();
  play5();



  YMF825.keyon(c, 0x54);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x50);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x53);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x51);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x50);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x48);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x46);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x44);
  delay(x/2);
  YMF825.keyoff(c);
  YMF825.keyon(c, 0x43);
  delay(x/2);
  YMF825.keyoff(c);

  YMF825.keyon(c, 0x41);
  delay(8*x);
  YMF825.keyoff(c);
  delay(8*x);
  }