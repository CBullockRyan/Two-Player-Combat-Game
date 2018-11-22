/*********************************************************************  
** Program Filename: Character.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is the base class for all the fantasy combat characters
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
using namespace std;

/*********************************************************************  
** Function: updateStrenPts
** Description: updates the strength points
** Parameters: damage
** Pre-Conditions: takes the amount of damage dealt
** Post-Conditions: strength points are updated from damage
*********************************************************************/
void Character::updateStrenPts(int damage){
	StrenPts=StrenPts-damage;
}

/*********************************************************************  
** Function: checkDead
** Description: checks whether strength points are depleted
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: if player is dead returns true.
*********************************************************************/
bool Character::checkDead(){
	if(StrenPts<1){
		return 1;
	}
	else
		return 0;
}