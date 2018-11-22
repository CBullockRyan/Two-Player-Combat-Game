/*********************************************************************  
** Program Filename: Blue.h
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for the Blue Men
** Input: none
** Output: none
*********************************************************************/
#ifndef BLUE_H
#define BLUE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

class Blue: public Character{
	public:
		Blue();
		int attack();
		int defense(int); 
		void printStatus();
};

#endif