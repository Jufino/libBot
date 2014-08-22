#ifndef _LIBBOT_H
#define _LIBBOT_H

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#define SDA 3
#define SCL 2
#include <i2c.h>

void cam(unsigned char comm,int pos);
unsigned char getULT(unsigned char por);

#endif
