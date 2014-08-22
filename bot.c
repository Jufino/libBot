#include "libbot.h"

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
