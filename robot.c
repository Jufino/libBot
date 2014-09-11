#include <stdio.h>
#include <unistd.h>

#define SDA 3
#define SCL 2
#include <bot.h>
#include <termios.h>
#include <fcntl.h>
int main(void){
initRobot();
cam('H',0);
cam('V',210);
return 1;
}
