#ifndef TEST_HPP
#define TEST_HPP
#include<iostream>
#include<cassert>
#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
 
#include"linkedlist.hpp" 
 
extern bool m_gameOver;
 
void test_v1()
{
	Setup();
	while(!m_gameOver){
		Draw();
		Input();
		Logic();
	}

}
void test_v2()
{
	//empty body
}
void test_v3()
{
	//empty body
}
 
 
#endif // TEST_HPP
