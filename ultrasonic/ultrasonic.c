#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

void trig()
{
   // Clear the trigger pin (PB2)
    PORTB &= ~(1 << PB2);
    _delay_us(2);
    // Set the trigger pin high
    PORTB |= (1 << PB2);
    _delay_us(10); // Duration for trigger pulse
    // Clear the trigger pin
    PORTB &= ~(1 << PB2);
}

void setup()
{
  /*
    LED is output on pin 12
    Echo is input on pin 11
    Trigger is output on pin 10
  */
   DDRB |= (1 << PB2) | (1 << PB4);  // Set PB2 and PB4 as outputs
   DDRB &= ~(1 << PB3);               // Set PB3 as input
}

void loop()
{
  trig();
  //If echo is returned turn high
  if ((PINB & (1 << PB3)) == (1 << PB3)) {
    // PB3 (pin11 -> echo pin) is high so turn off pin 12 which is the led
    PORTB &= ~(1 << PB4); //PORTB
  } else {
    // PB3 (pin11 -> echo pin) is low so turn on pin 12 which is the led
    PORTB |= (1 << PB4); // PORTB
  }
}

int main()
{
  setup();
  while(1)
  {
    loop();
  }
}
