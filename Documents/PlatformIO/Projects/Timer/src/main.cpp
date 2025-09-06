// #include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 20000000UL  // CPUクロック周波数

#define DATA_BIT   4  // PA4
#define OE_BIT  5  // PA5
#define LATCH_BIT  6  // PA6
#define CLOCK_BIT 7  // PA7
#define PRESSED(pin) (!(VPORTA.IN & (1 << (pin))))

#define LEFT 1
#define RIGHT 0

const uint8_t segnum[4]= {
  0b11111110, // 1(LEFT)
  0b11111101, // 2
  0b11111011, // 3
  0b11110111, // 4(RIGHT)
};
const uint8_t minnum[10] = {0x3F, 0x06, 0b01011011, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
const uint8_t secnum[10] = {0x3F, 0x30, 0x5B, 0x79, 0x74, 0x6D, 0b01101111, 0b00111100, 0x7F, 0b01111101};
const uint8_t wait[8] = {0x01, 0x02, 0x04, 0x08, 0x08, 0x10, 0x20, 0x01};


  // const uint8_t MODE[3] = {0x40, 0x50, 0x60}; // mode data
volatile uint8_t received_data = 0x00;
volatile bool received_check = false;



void ShiftInit() {
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0);  // disable the clock prescaler
  VPORTA.DIR = 0xF0; // initialize VPORTA
  PORTA.PIN1CTRL = PORT_PULLUPEN_bm;
  PORTA.PIN2CTRL = PORT_PULLUPEN_bm;
  VPORTA.OUT &= ~(1 << OE_BIT); // set OE_BIT to LOW
}

void pulseClock() {
  VPORTA.OUT |= (1 << CLOCK_BIT); // set CLOCK_BIT to HIGH
  _delay_us(1); // wait for 1 us
  VPORTA.OUT &= ~(1 << CLOCK_BIT); // set CLOCK_BIT to LOW
}

uint8_t upper8(uint16_t val) {
  return (uint8_t)((val >> 8) & 0xFF); // return the upper 8 bits
}

uint8_t lower8(uint16_t val) {
  return (uint8_t)(val & 0xFF); // return the lower 8 bits
}

uint16_t bitplus(uint8_t upper, uint8_t lower) {
  return ((uint16_t)upper << 8) | (uint16_t)lower;
}

void myShiftOut_fast(uint8_t val, uint8_t num) {
  uint16_t shiftbit;
  shiftbit = bitplus(segnum[(int)num], val); // combine upper and lower bytes
  VPORTA.OUT &= ~(1 << LATCH_BIT); // set LATCH_BIT to LOW
  for (int8_t i = 15; i >= 0; i--) {
    if (shiftbit & (1 << i)) {
      VPORTA.OUT |= (1 << DATA_BIT); // set DATA_BIT to HIGH
    } else {
      VPORTA.OUT &= ~(1 << DATA_BIT); // set DATA_BIT to LOW
    }
    pulseClock(); // pulse the clock
  }
  VPORTA.OUT |= (1 << LATCH_BIT); // set LATCH_BIT to HIGH
}

void ShiftOut(uint16_t val, uint8_t LR) {
  uint8_t upper = upper8(val); // get the upper byte
  uint8_t lower = lower8(val); // get the lower byte
  if(LR == LEFT) {
    myShiftOut_fast(upper, 0); // shift out the upper byte for LEFT
    _delay_ms(1);
    myShiftOut_fast(lower, 1); // shift out the lower byte for LEFT
    _delay_ms(1);
  } else {
    myShiftOut_fast(upper, 3); // shift out the upper byte for RIGHT
    _delay_ms(1);
    myShiftOut_fast(lower, 2); // shift out the lower byte for RIGHT
    _delay_ms(1);
  }
}

uint16_t timeculc(uint16_t val, uint8_t LR) {
  uint8_t lower, upper, templower, tempupper;
  uint16_t result;
  lower = val % 10;
  upper = (val-lower) / 10;
  if (LR == LEFT){
    templower = minnum[lower];
    tempupper = minnum[upper];
  } else {
    templower = secnum[lower];
    tempupper = secnum[upper];
  }
  result = bitplus(tempupper, templower); // combine upper and lower bytes
  return result; // return the combined value
}

void Timer(int time) {
  uint16_t min;
  uint16_t sec;
  sec = (uint16_t)(time % 60); // calculate seconds
  min = (uint16_t)((time-sec) / 60); // calculate minutes
  ShiftOut((timeculc(sec, RIGHT) | (0x8000)), RIGHT);
  ShiftOut((timeculc(min, LEFT) | (0x0080)), LEFT);
}



volatile uint16_t seconds = 0;  // 経過秒数

void TimerInit(void) {
  // TCA0 を分周して 1Hz 割り込みに設定
  // 分周 1024 を選択
  TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1024_gc;
  // 周期設定
  // F_CPU / 1024 = 19531 Hz
  // 1秒ごとに割り込みしたいので PER = 19531-1
  TCA0.SINGLE.PER = 19531 - 1;
  // オーバーフロー割り込みを有効化
  TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
  // タイマ有効化
  TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm;
  // グローバル割り込み有効化
  sei();
}

// 割り込みハンドラ
ISR(TCA0_OVF_vect) {
  seconds++; // 1秒ごとにカウントアップ
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm; // フラグクリア
}




int main() {
  ShiftInit(); // initialize the shift register
  TimerInit(); // initialize the timer
  bool mode=false;
  while(1){
    if (!mode) {
      ShiftOut(0x0000, LEFT);
      ShiftOut(0x0000, RIGHT);
      if (PRESSED(1)) {
        mode = true;
      }
    }
    if (mode) {
      Timer(seconds);
      _delay_ms(1);
            if (PRESSED(2)) {
        mode = false;
        seconds = 0;
      }
      static uint16_t old_sec = 0;
      if (seconds != old_sec) {
        old_sec = seconds;
      }
      ShiftOut(0x0000, LEFT);
      ShiftOut(0x0000, RIGHT);
      _delay_us(1);
    }
  }
  return 0;
}
