#gcc -g
CC=$(CROSS_COMPILE)gcc -g
TARGET=bot

robot:robot.c
	$(CC) robot.c -lbot -o robot

bot.o:bot.c
	$(CC) -c bot.c 

install: bot.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a bot.o
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/
	rm -f bot.o
	rm -f lib$(TARGET).a
clean:
	rm /usr/lib/lib$(TARGET).a
	rm /usr/include/bot.h
