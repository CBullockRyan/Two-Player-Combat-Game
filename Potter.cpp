/*********************************************************************  
** Program Filename: Potter.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for the Harry Potter
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Potter.h"
using namespace std;

/*********************************************************************  
** Function: Potter
** Description: constructor sets values specific to this character
** Parameters: string for which player it is
** Pre-Conditions: none
** Post-Conditions: object is initialized
*********************************************************************/
Potter::Potter(){
	A_num_dice=2;
	A_dice_size=6;
	D_num_dice=2;
	D_dice_size=6;
	Armor=0;
	StrenPts=10;
	life_flag=0;
}

/*********************************************************************  
** Function: attack  
** Description: rolls the attack dice and keeps track of hits
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of hits is returned
*********************************************************************/
int Potter::attack(){
	int hits=0;
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~HARRY POTTER ATTACK~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int i=0; i<A_num_dice; i++){
		temp=rand()%A_dice_size+1;
		cout<<"Roll "<<i<<": "<<temp<<endl;
		hits=hits+temp;
	}
	cout<<"Total hits: "<<hits<<endl;
	return hits;
}

/*********************************************************************  
** Function: defense  
** Description: rolls defence dice and subtracts from damage
** Parameters: int total hits dealt by attacker
** Pre-Conditions: attack for the other player must have been called
** Post-Conditions: total damage returned
*********************************************************************/
int Potter::defense(int damage){
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~HARRY POTTER DEFENSE~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int i=0; i<D_num_dice; i++){
		temp=rand()%D_dice_size+1;
		cout<<"Roll "<<i<<": "<<temp<<endl;
		damage=damage-temp;
	}
	cout<<"Subtracting Armor from damage..."<<endl;
	damage=damage-Armor;
	if(damage<0){
		damage=0;
	}
	cout<<"Total Damage Taken: "<<damage<<endl;
	return damage;
}

/*********************************************************************  
** Function: printStatus  
** Description: prints out current status of player
** Parameters: none
** Pre-Conditions: a round must have been conducted
** Post-Conditions: prints status to screen
*********************************************************************/
void Potter::printStatus(){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~HARRY POTTER STATUS~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Remaining Strength Points: "<<StrenPts<<endl;
}

/*********************************************************************  
** Function: checkDead  
** Description: if Harry Potter dies for the first time his health resets
**				to 10 and if its the second time he actually dies
** Parameters: none
** Pre-Conditions: flag must be triggered
** Post-Conditions: if player is dead returns true
*********************************************************************/
bool Potter::checkDead(){
	if(StrenPts<1 && life_flag==0){
		cout<<"Harry Potter's power of HOGWARTS has been activated. His total Strength Points return to 10."<<endl;
		StrenPts=10;
		life_flag=1;
		return 0;
	}
	else if(StrenPts>0){
		return 0;
	}
	else
		return 1;
}