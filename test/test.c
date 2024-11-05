#define F_CPU 16000000UL // 16 MHz clock speed of Arduino Uno

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set pin 13 (PB5) as an output
    DDRB |= (1 << PB5);

    while (1) {
        // Turn on the LED
        PORTB |= (1 << PB5);
        _delay_ms(5000);

        // Turn off the LED
        PORTB &= ~(1 << PB5);
        _delay_ms(5000);
    }
}
