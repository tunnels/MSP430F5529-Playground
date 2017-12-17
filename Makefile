ASMINPUT=assembly/button_hold.asm
CINPUT=C/blink.c

#DEPS=

OUTPUT=p.elf
CFLAGS=-Wall -g -mmcu=msp430f5529
AFLAGS=-D_GNU_ASSEMBLER_ -x assembler-with-cpp -c

CC=msp430-gcc
MSPDEBUG=mspdebug

all:
	$(CC) $(CINPUT) -o $(OUTPUT) $(CFLAGS)

asm:
	$(CC) $(AFLAGS) $(ASMINPUT) -o $(OUTPUT) $(CFLAGS)

asmflash: asm
	$(LD_LIBRARY_PATH) $(MSPDEBUG) tilib "prog $(OUTPUT)"

flash: all
	$(LD_LIBRARY_PATH) $(MSPDEBUG) tilib "prog $(OUTPUT)"

clean:
	rm p.elf
