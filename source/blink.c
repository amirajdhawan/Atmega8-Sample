// this is the header file that tells the compiler what pins and ports, etc.
// are available on this chip.
#include <avr/io.h>

// define which pin the LED should use
// based on ATmega8 datasheet, pin 15 is PB1
#define LED PB1
#define F_CPU 2000000
// Some macros that make the code more readable
#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

// this is just a program that 'kills time' in a calibrated method
void delay_ms(uint16_t ms) {
  uint16_t delay_count = F_CPU / 17500;
  volatile uint16_t i;

  while (ms != 0) {
    for (i=0; i != delay_count; i++);
    ms--;
  }
}

int main(void) {
  // initialize the direction of PORTB #6 to be an output
  set_output(DDRB, LED);  

  while (1) {
    // turn on the LED for 200ms
    output_high(PORTB, LED);
    delay_ms(500);
    // now turn off the LED for another 200ms
    output_low(PORTB, LED);
    delay_ms(500);
    // now start over
  }
}
