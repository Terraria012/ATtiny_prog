// #include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 20000000UL  // CPUクロック周波数

#define DATA_BIT   4  // PA4
#define CLOCK_BIT  5  // PA5
#define LATCH_BIT  6  // PA6
#define TOGGLE_BIT 7  // PA7

#define HIGH 1
#define LOW 0
const uint8_t num[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
const uint8_t wait[8] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00001000, 0b00010000, 0b00100000, 0b00000001};
const uint8_t text[12] = {
    0x00, //blank
    0x5E, //D
    0x6D, //S
    0x73, //P
    0x79, //E
    0x71, //F
    0x71, //F
    0x79, //E
    0x39, //C
    0x78, //T
    0x79, //E
    0x50, //R
  };
  const uint8_t yen[7] {
    0x00,
    0b01101101,
    0x3F,
    0x3F,
    0x6E,
    0x79,
    0b01010100,
  };


  // const uint8_t MODE[3] = {0x40, 0x50, 0x60}; // mode data
volatile uint8_t received_data = 0x00;
volatile bool received_check = false;

void I2C_SlaveInit(uint8_t address) {
  TWI0.SADDR = address << 1; // set slave address
  TWI0.SCTRLA = TWI_ENABLE_bm | TWI_APIEN_bm | TWI_DIEN_bm; // enable TWI, address interrupt, data interrupt
  sei(); // enable global interrupts
}

ISR(TWI0_TWIS_vect) { // TWI interrupt service routine
  if (TWI0.SSTATUS & TWI_APIF_bm) {
    TWI0.SSTATUS |= TWI_APIF_bm; // clear address flag
  }
  if (TWI0.SSTATUS & TWI_DIF_bm) {
    received_data = TWI0.SDATA; // read data
    received_check = true;      // set received check
    TWI0.SCTRLB = TWI_SCMD_COMPTRANS_gc; // send ACK
  }
}

void ShiftInit() {
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0);  // disable the clock prescaler
  VPORTA.DIR |= (1 << DATA_BIT) | (1 << CLOCK_BIT) | (1 << LATCH_BIT) | (1 << TOGGLE_BIT); // initialize VPORTA
  VPORTA.OUT &= ~(1 << TOGGLE_BIT); // set TOGGLE_BIT to LOW
}

void pulseClock() {
  VPORTA.OUT |= (1 << CLOCK_BIT); // set CLOCK_BIT to HIGH
  _delay_us(1); // wait for 1 us
  VPORTA.OUT &= ~(1 << CLOCK_BIT); // set CLOCK_BIT to LOW
}

void myShiftOut_fast(uint8_t val) {
  for (int8_t i = 7; i >= 0; i--) {
    if (val & (1 << i)) {
      VPORTA.OUT |= (1 << DATA_BIT); // set DATA_BIT to HIGH
    } else {
      VPORTA.OUT &= ~(1 << DATA_BIT); // set DATA_BIT to LOW
    }
    pulseClock(); // pulse the clock
  }
}

void ShiftOut(uint8_t val, int x, int time) {
  if (x == 0) {
    VPORTA.OUT &= ~(1 << TOGGLE_BIT); // set TOGGLE_BIT to LOW
    } else if (x == 1) {
    VPORTA.OUT |= (1 << TOGGLE_BIT); // set TOGGLE_BIT to HIGH
  }
  VPORTA.OUT &= ~(1 << LATCH_BIT); // set LATCH_BIT to LOW
  myShiftOut_fast(val); // send the value
  VPORTA.OUT |= (1 << LATCH_BIT); // set LATCH_BIT to HIGH

  for (int t=0;t<time;t++) {
    _delay_ms(1); // wait 1 ms
  }
}

void displayWait(int i) { // display wait animation
    if (i%8<4) {
      ShiftOut(wait[i%8], LOW, 100);
    } else if (i%8>=4) {
      ShiftOut(wait[i%8], HIGH, 100);
    }
}

void displayText(int i) { // display text animation
  for (int t=0;t<15;t++) {
    ShiftOut(text[(i+1)%12], LOW, 10);
    ShiftOut(text[i%12], HIGH, 10);
  }
  ShiftOut(0b00000000, LOW, 3);
}

void displayText1(int i) {
  for (int t=0;t<20;t++) {
    ShiftOut(yen[(i+1)%7], LOW, 10);
    ShiftOut(yen[i%7], HIGH, 10);
  }
  ShiftOut(0b00000000, LOW, 3);
}

int main() {
  ShiftInit();
  I2C_SlaveInit(0x20); // Initialize I2C slave with address 0x20
  int i=0;
  int mode = 0;
  int NUM;
  while (1) {
    if (mode == 0) {
      if (i<24) {
        displayWait(i);
      }
      if (i>=24 && i<48) {
        displayText(i);
        // if (received_data == 0x40 && received_check) {
        //   mode = 1; // if data received, change mode to 1
        //   received_check = false; // reset received check
        
        //   received_data = 0x00; // reset received data
        // }
      }
      i++;
    }
    if (mode == 1) {
      if (received_data != 0x40) {
        NUM = (int)received_data;
        ShiftOut(num[NUM%10], LOW, 20);
        ShiftOut(0b00000000, LOW, 5);
        ShiftOut(num[(NUM-NUM%10)/10], HIGH, 20);
        ShiftOut(0b00000000, HIGH, 5);
      } else {
        mode = 2;
        received_data = (uint8_t)NUM; // reset received data
      }
    }
    if (mode == 2) {
      ShiftOut(num[NUM%10], LOW, 10);
      ShiftOut(num[(NUM-NUM%10)/10], HIGH, 10);
      if (received_data == 0x40) {
        mode = 1; // if data received, change mode to 1
        received_check = false; // reset received check
        received_data = (uint8_t)NUM; // reset received data
      }
    }
  }
  return 0;
}
