/*********************************************************************  
** Program Filename: Gollum.h
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for Gollum
** Input: none
** Output: none
*********************************************************************/
#ifndef GOLLUM_H
#define GOLLUM_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

class Gollum: public Character{
	public:
		Gollum();
		int attack(); //5% chance gollum gets a 3d6 attack RING power
		int defense(int);
		void printStatus();
};

#endif