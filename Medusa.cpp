/*********************************************************************  
** Program Filename: Medusa.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for Medusa
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Medusa.h"
using namespace std;

/*********************************************************************  
** Function: Medusa  
** Description: constructor sets values specific to this character
** Parameters: string for which player it is
** Pre-Conditions: none
** Post-Conditions: object is initialized
*********************************************************************/
Medusa::Medusa(){
	A_num_dice=2;
	A_dice_size=6;
	D_num_dice=1;
	D_dice_size=6;
	Armor=3;
	StrenPts=8;
}

/*********************************************************************  
** Function: attack  
** Description: rolls the attack dice and keeps track of hits, also
**				automatically wins if 12 is rolled
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of hits is returned
*********************************************************************/
int Medusa::attack(){
	int hits=0;
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~MEDUSA ATTACK~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int i=0; i<A_num_dice; i++){
		temp=rand()%A_dice_size+1;
		cout<<"Roll "<<i<<": "<<temp<<endl;
		hits=hits+temp;
	}
	if(hits==12){
		return 900;
	}
	else{
		cout<<"Total hits: "<<hits<<endl;
		return hits;
	}
}

/*********************************************************************  
** Function: defense  
** Description: rolls defence dice and subtracts from damage
** Parameters: int total hits dealt by attacker
** Pre-Conditions: attack for the other player must have been called
** Post-Conditions: total damage returned
*********************************************************************/
int Medusa::defense(int damage){
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~MEDUSA DEFENSE~~~~~~~~~~~~~"<<endl;
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
void Medusa::printStatus(){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~MEDUSA STATUS~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Remaining Strength Points: "<<StrenPts<<endl;
}