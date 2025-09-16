#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#define F_CPU 20000000UL
#define TWI_BAUD(F_SCL) (((F_CPU / (2 * F_SCL)))-5)

const uint8_t cmd[4] = {0x10, 0x20, 0x30, 0x40}; // command data
const uint8_t address = 0x20; // I2C address of the slave device

void I2C_init(void) {
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0);  // Disable the clock prescaler
    TWI0.MBAUD = TWI_BAUD(100000);  // 100kHz
    TWI0.MCTRLA = TWI_ENABLE_bm;    // enable TWI
    TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc; // set bus state to idle 
}

void I2C_write(uint8_t address, uint8_t data) { // start condition
    TWI0.MADDR = (address << 1);  // mode write

    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // waiting for write

    if (TWI0.MSTATUS & TWI_RXACK_bm) { // if NACK received, stop and return
        TWI0.MCTRLB = TWI_MCMD_STOP_gc;
        return;
    }

    TWI0.MDATA = data;
    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // complete write

    TWI0.MCTRLB = TWI_MCMD_STOP_gc; // stop condition
}

// Rotary encoder function
volatile int state_a = 0;
volatile int state_b = 0;
volatile int edge_a;
volatile int edge_b;
volatile int count = 0;
volatile bool sw = false;
// volatile bool sw_state = false;
#define Phase_A 4
#define Phase_B 5
#define SW 6

void rotary_encode_Init() {
  VPORTA.DIR &= ~(1 << Phase_A); // Set PA4 as input
  VPORTA.DIR &= ~(1 << Phase_B); // Set PA5 as input
  VPORTA.DIR &= ~(1 << SW); // Set PA6 as input
  PORTA.PIN4CTRL = PORT_PULLUPEN_bm | PORT_ISC_BOTHEDGES_gc; // Enable pull-up and both edges interrupt
  PORTA.PIN5CTRL = PORT_PULLUPEN_bm | PORT_ISC_BOTHEDGES_gc; // Enable pull-up and both edges interrupt
  PORTA.PIN6CTRL = PORT_PULLUPEN_bm | PORT_ISC_BOTHEDGES_gc; // Enable pull-up and both edges interrupt
  VPORTA.INTFLAGS = PIN4_bm | PIN5_bm | PIN6_bm; // Clear interrupt flag
  // sei();
}

ISR(PORTA_PORT_vect) { // If switch is pressed
    if ((VPORTA.IN & (1 << SW))) {
      sw = true;
    }
  // Rotary encoder interrupt
    if (VPORTA.IN & (1 << Phase_A) && state_a == 0) { // If Phase A is high
      edge_a = 1; state_a = 1;
    } else if (!(VPORTA.IN & (1 << Phase_A)) && state_a == 1) { // If Phase A is high
      edge_a = -1; state_a = 0;
    } else {
      edge_a = 0;
    }
    if (VPORTA.IN & (1 << Phase_B) && state_b == 0) { // If Phase B is high
      edge_b = 1; state_b = 1;
    } else if (!(VPORTA.IN & (1 << Phase_B)) && state_b == 1) { // If Phase B is high
      edge_b = -1; state_b = 0;
    } else {
      edge_b = 0;
    }
  PORTA.INTFLAGS = PIN4_bm | PIN5_bm | PIN6_bm; // Clear interrupt flag
      I2C_write(address, (uint8_t)((count%200)/2));
        if (edge_a == 1) {
      count += (VPORTA.IN & (1 << Phase_B)) ? -1 : 1; // if Phase B is high, count up, else count down
    } 
    if (edge_a == -1) {
      count += (VPORTA.IN & (1 << Phase_B)) ? 1 : -1; // if Phase B is high, count down, else count up
    }
    if (edge_b == 1) {
      count += (VPORTA.IN & (1 << Phase_A)) ? 1 : -1; // if Phase A is high, count down, else count up
    }
    if (edge_b == -1) {
      count += (VPORTA.IN & (1 << Phase_A)) ? -1 : 1; // if Phase A is high, count up, else count down
    }
    if (count < 0) {
      count = 255;
    }
    if (count > 255) {
      count = 0;
    }
    _delay_us(1);
    if (sw) {
      sw = false;
      I2C_write(address, 0x40); // Send 0xFF to the slave device
    }
}


int main() {
  rotary_encode_Init(); // Initialize rotary encoder
  I2C_init(); // Initialize I2C
  _delay_ms(4200); // Wait for 5 seconds
  VPORTA.DIR |= 0b00111110;
  while (1) {
    VPORTA.OUT = 0b00110100;
  }
  return 0;
}
