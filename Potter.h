/*********************************************************************  
** Program Filename: Potter.h
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for Harry Potter
** Input: none
** Output: none
*********************************************************************/
#ifndef POTTER_H
#define POTTER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

class Potter: public Character{
	private:
		bool life_flag;
	public:
		Potter();
		int attack();
		int defense(int);
		void printStatus();
		bool checkDead(); 
};

#endif