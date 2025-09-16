// #include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 20000000UL

#define DATA_BIT   4  // PA4
#define OE_BIT     5  // PA5
#define LATCH_BIT  6  // PA6
#define CLOCK_BIT  7  // PA7
#define PRESSED(pin) (!(VPORTA.IN & (1 << (pin))))

#define LEFT  1
#define RIGHT 0

#define PULSE_BIT 0   // PB0
#define ADC_CH    3   // PA3

// --- グローバル変数 ---
volatile int voltage = 0;

const uint8_t segnum[4]= {
  0b11111110, // 1(LEFT)
  0b11111101, // 2
  0b11111011, // 3
  0b11110111, // 4(RIGHT)
};
const uint8_t minnum[10] = {0x3F, 0x06, 0b01011011, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
const uint8_t secnum[10] = {0x3F, 0x30, 0x5B, 0x79, 0x74, 0x6D, 0b01101111, 0b00111100, 0x7F, 0b01111101};
const uint8_t wait[8] = {0x01, 0x02, 0x04, 0x08, 0x08, 0x10, 0x20, 0x01};

void ShiftInit() {
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0);  // disable the clock prescaler
  VPORTA.DIR = 0xF0; // initialize VPORTA (PA4-7出力)
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

void printvoltage(int val) {
  uint16_t left, right;
  left = bitplus(minnum[(val%10000-val%1000)/1000], minnum[(val%1000-val%100)/100]); // combine upper and lower bytes for LEFT
  right = bitplus(secnum[(val%100-val%10)/10], secnum[val%10]); // combine upper and lower bytes for RIGHT
  ShiftOut(left, LEFT); // display on LEFT
  ShiftOut(right, RIGHT); // display on RIGHT
}

// =====================================================
//  ADC制御
// =====================================================
void ADC_Init(void) {
    VPORTA.DIR &= ~(1 << ADC_CH);  // PA3を入力
    PORTA.PIN3CTRL &= ~PORT_ISC_gm; // デフォルト入力設定

    ADC0.CTRLC = ADC_PRESC_DIV4_gc     // 分周 = 4
               | ADC_REFSEL_VDDREF_gc; // VDDを基準電圧に

    ADC0.CTRLA = ADC_ENABLE_bm;        // ADC有効化
    ADC0.MUXPOS = ADC_MUXPOS_AIN3_gc;  // 入力チャンネル = PA3(ADC3)
}

uint16_t ADC_Read(void) {
    ADC0.COMMAND = ADC_STCONV_bm;              // 変換開始
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));  // 終了待ち
    ADC0.INTFLAGS = ADC_RESRDY_bm;             // フラグクリア
    return ADC0.RES;                           // 10bit結果
}

// =====================================================
//  パルス制御
// =====================================================
void PulseInit(void) {
    VPORTB.DIR |= (1 << PULSE_BIT);   // PB0出力
    VPORTB.OUT &= ~(1 << PULSE_BIT);  // 初期はLow
}

// void Pulse2ms(void) {
//     VPORTB.OUT |= (1 << PULSE_BIT);   // High
//     _delay_ms(2);                     // 2msパルス幅
//     VPORTB.OUT &= ~(1 << PULSE_BIT);  // Low
// }

int main() {
  ShiftInit();    // 7セグ初期化
  PulseInit();    // パルス出力初期化
  ADC_Init();     // ADC初期化

  uint16_t voltage = 0; // 初期電圧値
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
      VPORTB.OUT |= (1 << PULSE_BIT);  // パルス出力 High
      for (int i = 0; i < 200; i++) {  // 200回 = 2ms / 10µs
        if (i == 100) {
          voltage = ADC_Read();   // ADC結果読む（要: ADC初期化済み）
        }
          _delay_us(10); // 10µs 間隔でサンプリング
      }
      VPORTB.OUT &= ~(1 << PULSE_BIT); // パルス出力 Low
      printvoltage(voltage);  // 最新の電圧値を表示
      if (PRESSED(2)) {
        mode = false;
        voltage = 0;
      }
    }
  }
  return 0;
}

