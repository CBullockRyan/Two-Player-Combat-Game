#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Character{
	protected:
		int A_num_dice;
		int A_dice_size;
		int D_num_dice;
		int D_dice_size;
		int Armor;
		int StrenPts;
	public:
		virtual int attack()=0;
		virtual int defense(int)=0;
		void updateStrenPts(int);
		virtual bool checkDead();
		virtual void printStatus()=0;
};

#endif