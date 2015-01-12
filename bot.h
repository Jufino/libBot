#ifndef _BOT_H
#define _BOT_H
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void initRobot(void);
int kick(void);
int motors(int rychlost1,int rychlost2,int rychlost3,int rychlost4);
int m_(int uhol,unsigned char rychlost);
int m_stop(unsigned char brake,unsigned char rychlost);
int m_ot(unsigned char vlavo,unsigned char rychlost);
int LED1(unsigned char on);
int LED2(unsigned char on);
int LED3(unsigned char on);
int getSensors(char *dataSensors);
int getULT(char *dataULT);
int setMaxULT(char ult,char max);
#endif
