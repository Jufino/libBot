#ifndef _LIBBOT_H
#define _LIBBOT_H

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <i2c.h>

void initRobot();
void cam(unsigned char comm,int pos);
unsigned char getULT(unsigned char por);
void setMaxULT(unsigned char por,unsigned char max);
unsigned char getValIR();
unsigned char getIndexIR();
void kick();
void m_(int uhol,unsigned char rychlost);
void m_ot(unsigned char vlavo,unsigned char rychlost);
void LED1(unsigned char on);
void LED2(unsigned char on);
void LED3(unsigned char on);
#endif
