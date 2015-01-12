#include <stdio.h>
#include <unistd.h>

#include <bot.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void quit(char* msg, int retval);
int main(void){
	char data[9];
	initRobot();
	if(getSensors(&data[0]) == -1) printf("chyba\n");

//	if(getULT(&data[0]) == -1) printf("chyba\n");
//	int data[10];
//	int dataULT[10];	
//	readSensors(&data[0]);
//	readULT(&dataULT[0]);
	printf("%d\n",data[1]);
//	LED3(0);
	return 1;
}
void quit(char* msg, int retval)
{
        fprintf(stderr, "%s\n", msg);
        exit(retval);
}

