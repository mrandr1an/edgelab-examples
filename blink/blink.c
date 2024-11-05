#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

void setup()
{
  DDRB |= 0b010000; // PORTB5
}

void loop()
{
  PORTB |= 0b010000; // PORTB5
  _delay_ms(BLINK_DELAY_MS);

  PORTB &= ~ PORTB; // PORTB5
  _delay_ms(BLINK_DELAY_MS);
}

int main ()
{
  setup();
  while(1)
  {
    loop();
  }
}
