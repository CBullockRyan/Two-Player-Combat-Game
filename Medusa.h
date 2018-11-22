/*********************************************************************  
** Program Filename: Medusa.h
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for Medusa
** Input: none
** Output: none
*********************************************************************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

class Medusa: public Character{
	public:
		Medusa();
		int attack(); 
		int defense(int);
		void printStatus();
};

#endif