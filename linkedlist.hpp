
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include<iostream>
#include<unistd.h>
//#include<>// analog conio.h


#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
#define RED "\033[01;031m"

#include<stdio.h>
#include<sys/select.h>
#include<termios.h>
#include<stropts.h>

/////////////
#include<sys/ioctl.h> //for FIONREAD 

//#include<cstdio>

int _kbhit();
int _getch(void);

 
void Setup();
void Draw(); 
void Input(); 
void Logic();
 
#endif //LINKEDLIST_HPP
