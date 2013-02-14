OPTIMIZATION = -O3
CORELIB = ../core/core.a
CC = avr-gcc
CXX = avr-g++
OBJCOPY = avr-objcopy
INCLUDEFLAGS = -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard
CXXFLAGS = -c -g $(OPTIMIZATION) -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=101 $(INCLUDEFLAGS)

main.o: main.cpp Makefile
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

main.elf: main.o Makefile
	$(CC) $(OPTIMIZATION) -Wl,--gc-sections -mmcu=atmega328p -o main.elf main.o $(CORELIB) -lm 

main.hex: main.elf Makefile
	$(OBJCOPY) -O ihex -R .eeprom main.elf main.hex

.PHONY: upload clean
upload: main.hex Makefile
	avrdude -p m328p -P /dev/ttyACM0 -c arduino -b115200 -F -U flash:w:main.hex

clean:
	rm main.elf main.o
# avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /tmp/build1966569746215902677.tmp/test1.cpp.elf /tmp/build1966569746215902677.tmp/test1.cpp.eep 
# avr-objcopy -O ihex -R .eeprom /tmp/build1966569746215902677.tmp/test1.cpp.elf /tmp/build1966569746215902677.tmp/test1.cpp.hex 