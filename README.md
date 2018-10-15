# ATmega8 Sample

This repository is an introduction to the procedure of compiling C source files, linking them and creating a **hex** file, then finally uploading it to an *ATmega8* microprocessor.

## Compilation

Run following commands respectively to create a **hex** file.

    avr-gcc -mmcu=atmega8 -Wall blink.c -o blink.o
    avr-objcopy -j.text blink.o blink.hex
    sudo avrdude -c usbasp -p attiny2313 -U flash:w:blink.hex

## Source

There are three files in **source** directory, each of them representing the output file from compilation progress.  
You can modify the C source file, re-compile it, or simply use the hex file to upload it on your ATmega8 microprocessor.