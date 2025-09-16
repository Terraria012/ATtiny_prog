#ifndef _SIMPLE_YMF825_H_
#define _SIMPLE_YMF825_H_

#include <stdint.h>
#include <Arduino.h>

// tone number
#define GRAND_PIANO     0
#define E_PIANO         1
#define TENOR_SAX       2
#define PICK_BASS       3


// I/O voltage
#define IOVDD_5V        0
#define IOVDD_3V3       1

// number of channels
#define CH_MAX          16

// Simple YMF825 driver
class SimpleYMF825
{
public:
    void begin(int drv_sel = IOVDD_5V);
    // void keyon    (int ch, int octave, int key, int vol);
    // void key  (int ch, int octave, int key, int time);
    void keyon(uint8_t ch, uint8_t data);
    void keyoff   (uint8_t ch);
    void setTone  (int ch, int tone);
    // void setKey   (int ch, int octave, int key);
    void setVolume(int ch, int vol);
    void setMasterVolume(int vol);

private:
    uint8_t m_tone[CH_MAX];};

#endif
