#include "bot.h"
void initRobot(){
	i2c_init();
}
void kick(){
	i2c_start();
	i2c_write(0x12);
       	i2c_write(12);
        i2c_stop();
}
void m_(int uhol,unsigned char rychlost){
	i2c_start();
	i2c_write(0x12);
	if(uhol < 0)		i2c_write(11);
	else if(uhol < 45) 	i2c_write(1);
	else if(uhol < 90) 	i2c_write(2);
	else if(uhol < 135) 	i2c_write(3);
	else if(uhol < 180) 	i2c_write(4);
	else if(uhol < 225) 	i2c_write(5);
	else if(uhol < 270) 	i2c_write(6);
	else if(uhol < 315) 	i2c_write(7);
	else if(uhol < 360) 	i2c_write(8);
	if(uhol != 11)		i2c_write(rychlost);
	i2c_stop();
}
void m_ot(unsigned char vlavo,unsigned char rychlost){
	i2c_start();
        i2c_write(0x12);
	if (vlavo == 1) i2c_write(9);
	else 		   i2c_write(10);
        i2c_write(rychlost);
        i2c_stop();
}
void LED1(unsigned char on){
        i2c_start();
        i2c_write(0x12);
        if(on == 0)  	i2c_write(13);
	else 		i2c_write(14);
        i2c_stop();
}
void LED2(unsigned char on){
        i2c_start();
        i2c_write(0x10);
        if(on == 1)     i2c_write(19);
        else            i2c_write(20);
        i2c_stop();
}
void LED3(unsigned char on){
        i2c_start();
        i2c_write(0x10);
        if(on == 1)     i2c_write(21);
        else            i2c_write(22);
        i2c_stop();
}

unsigned char getIndexIR(){
	i2c_start();
        i2c_write(0x12);
        i2c_start();
        i2c_write(0x13);
        unsigned char hod = i2c_read(1);
        i2c_stop();
	return hod;
}
unsigned char getValIR(){
        i2c_start();
        i2c_write(0x12);
        i2c_start();
        i2c_write(0x13);
	i2c_read(0);
	unsigned char hod = i2c_read(1);
        i2c_stop();
        return hod;
}
void cam(unsigned char comm,int pos){
        if(comm == 'H'){//horizontal
		pos +=330;
		if(pos > 1000)	   pos = 1000;
		else if(pos < 330) pos = 330;
                i2c_start();
                i2c_write(0x08);
                i2c_write(1);
                i2c_write(pos&0xFF);
		i2c_write((pos>>8)&0xFF);
                i2c_stop();
        }
        else if(comm == 'V'){//vertical
		pos=550-pos;      
		if(pos < 0) 	 pos = 0;  
		else if(pos>550) pos = 550;
        	i2c_start();
                i2c_write(0x08);
                i2c_write(2);
		i2c_write(pos&0xFF);
                i2c_write((pos>>8)&0xFF);
                i2c_stop();
        }
	else if(comm == 'B'){//default vertical
		pos = 550-pos;
		if(pos < 0) 	 pos = 0;
		else if(pos>550) pos = 550;
		i2c_start();
                i2c_write(0x08);
                i2c_write(3);
                i2c_write(pos&0xFF);
                i2c_write((pos>>8)&0xFF);
                i2c_stop();
	}
        else if(comm == 'J'){//default horizontal
		pos += 330;
		if(pos > 1000) 	   pos = 1000;
		else if(pos < 330) pos = 330;
                i2c_start();
                i2c_write(0x08);
                i2c_write(4);
                i2c_write(pos&0xFF);
                i2c_write((pos>>8)&0xFF);
                i2c_stop();
        }
}

unsigned char getULT(unsigned char por){       
	i2c_start();
        i2c_write(0x10);
        i2c_write(por);
        i2c_start();
        i2c_write(0x11);
        unsigned char hod = i2c_read(1);
        i2c_stop();
	return hod;
}
void setMaxULT(unsigned char por,unsigned char max){
                i2c_start();
                i2c_write(0x10);
                i2c_write(por+6);
                i2c_write(max);
                i2c_stop();
}
