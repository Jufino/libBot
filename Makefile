
CC=$(CROSS_COMPILE)gcc -g
TARGET=bot

bot.o:bot.c
	$(CC) -c bot.c

install: bot.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a bot.o
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/

robot:robot.c
	$(CC) robot.c -lbot -li2c -lgpio -o robot
