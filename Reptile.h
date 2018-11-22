#ifndef REPTILE_H
#define REPTILE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

class Reptile: public Character{
	public:
		Reptile();
		int attack();
		int defense(int);
		void printStatus();
};

#endif