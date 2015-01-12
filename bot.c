#include "bot.h"
int file;
void initRobot(void){
	char *filename = "/dev/i2c-2";
	if ((file = open(filename, O_RDWR)) < 0) {
    		perror("Failed to open the i2c bus");
    		exit(1);
	}
}
int kick(void){
	char  buf[1];
	int addr = 0x09;
	if (ioctl(file, I2C_SLAVE, addr) < 0) {
    		printf("Failed to acquire bus access and/or talk to slave.\n");
    		exit(1);
	}
	buf[0] = 22;
	if (write(file,buf,1) != 1) return -1;
	return 0;
}
int motors(int rychlost1,int rychlost2,int rychlost3,int rychlost4){
	if(rychlost1 > 255) 		rychlost1 =  255;
	else if (rychlost1 < -255) 	rychlost1 = -255;
	if(rychlost2 > 255) 		rychlost2 =  255;
	else if (rychlost2 < -255) 	rychlost2 = -255;
	if(rychlost3 > 255) 		rychlost3 =  255;
	else if (rychlost3 < -255) 	rychlost3 = -255;
	if(rychlost4 > 255) 		rychlost4 =  255;
	else if (rychlost4 < -255) 	rychlost4 = -255;

	char  buf[6];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }

	buf[0] = 20;
	buf[1] = 0;
	if(rychlost1 > 0) buf[1] |= 1;
	else		  rychlost1 *= -1;
	if(rychlost2 > 0) buf[1] |= 2;
	else              rychlost2 *= -1;
	if(rychlost3 > 0) buf[1] |= 4;
	else              rychlost3 *= -1;
	if(rychlost4 > 0) buf[1] |= 8;
	else              rychlost4 *= -1;

	buf[2] = rychlost1;
	buf[3] = rychlost2;
	buf[4] = rychlost3;
	buf[5] = rychlost4;
	
        if (write(file,buf,6) != 6) return -1;
        return 0;
}
int m_(int uhol,unsigned char rychlost){
	char  buf[2];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }

	if(uhol <= 0)		buf[0] = 1;
	else if(uhol <= 45) 	buf[0] = 2;
	else if(uhol <= 90) 	buf[0] = 3;
	else if(uhol <= 135) 	buf[0] = 4;
	else if(uhol <= 180) 	buf[0] = 5;
	else if(uhol <= 225) 	buf[0] = 6;
	else if(uhol <= 270) 	buf[0] = 7;
	else if(uhol <= 315) 	buf[0] = 8;
	buf[1] = rychlost;
	if (write(file,buf,2) != 2) return -1;
        return 0;
}
int m_stop(unsigned char brake,unsigned char rychlost){
	char  buf[2];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
	if(brake == 1){
		buf[1] = 19;
		buf[2] = rychlost;
		if (write(file,buf,2) != 2) return -1;
	}
	else{
		buf[1] = 21;
        	if (write(file,buf,1) != 1) return -1;
	}
	return 0;
}
int m_ot(unsigned char vlavo,unsigned char rychlost){
	char  buf[2];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
	if (vlavo == 1) buf[0] = 9;
	else 		buf[0] = 10;
	buf[1] = rychlost;
        if (write(file,buf,2) != 2) return -1;
        return 0;
}
int LED1(unsigned char on){
	char  buf[1];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
        if (on == 1) buf[0] = 23;
        else         buf[0] = 24;
        if (write(file,buf,1) != 1) return -1;
        return 0;
}
int LED2(unsigned char on){
	char  buf[1];
        int addr = 0x08;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
        if (on == 1) buf[0] = 7;
        else         buf[0] = 8;
        if (write(file,buf,1) != 1) return -1;
        return 0;
}
int LED3(unsigned char on){
	char  buf[1];
        int addr = 0x08;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
        if (on == 1) buf[0] = 9;
        else         buf[0] = 10;
        if (write(file,buf,1) != 1) return -1;
        return 0;
}
int getSensors(char *dataSensors){
	char  buf[1];
        int addr = 0x09;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
        buf[0] = 25;
        if (write(file,buf,1) != 1) 	    return -1;
	if (read(file,dataSensors,9) != 9)  return -1;
	return 0;
}

int getULT(char *dataULT){     
	char data[6];	  
        char  buf[1];
        int addr = 0x08;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
        buf[0] = 1;
        if (write(file,buf,1) != 1)     return -1;
        if (read(file,dataULT,6) != 6)  	return -1;
//	printf("%d %d %d %d %d %d\n",data[0],data[1],data[2],data[3],data[4],data[5]);

        return 0;
}

int setMaxULT(char ult,char max){
	char  buf[2];
        int addr = 0x08;
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                printf("Failed to acquire bus access and/or talk to slave.\n");
                exit(1);
        }
	switch(ult){
		case 1: buf[0] = 11;
			buf[1] = max;
			if (write(file,buf,2) != 2)         return -1;
		break;
                case 2: buf[0] = 12;
                        buf[1] = max;
                        if (write(file,buf,2) != 2)         return -1;
                break;
                case 3: buf[0] = 13;
                        buf[1] = max;
                        if (write(file,buf,2) != 2)         return -1;
                break;
                case 4: buf[0] = 14;
                        buf[1] = max;
                        if (write(file,buf,2) != 2)         return -1;
                break;
                case 5: buf[0] = 15;
                        buf[1] = max;
                        if (write(file,buf,2) != 2)         return -1;
                break;
                case 6: buf[0] = 16;
                        buf[1] = max;
                        if (write(file,buf,2) != 2)         return -1;
                break;
	}
	return 0;
}
