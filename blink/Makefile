CFLAGS = -Wall -I. -g -Os -mmcu=atmega168 -DF_CPU=16000000
SRC = blink.c
OBJ = $(SRC:.c=.o)  # Automatically replace .c with .o

blink: blink.elf
	avr-objcopy -O ihex $< blink.hex

blink.elf: $(OBJ)
	avr-gcc $(CFLAGS) -o $@ $^

%.o: %.c
	avr-gcc $(CFLAGS) -c $< -o $@

burn: blink.hex
	avrdude -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:$<
clean:
	rm -f *.o *.elf *.hex
