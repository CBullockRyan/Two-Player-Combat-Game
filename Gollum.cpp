/*********************************************************************  
** Program Filename: Gollum.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for Gollum
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Gollum.h"
using namespace std;

/*********************************************************************  
** Function: Gollum 
** Description: constructor sets values specific to this character
** Parameters: string for which player it is
** Pre-Conditions: none
** Post-Conditions: object is initialized
*********************************************************************/
Gollum::Gollum(){
	A_num_dice=1;
	A_dice_size=6;
	D_num_dice=1;
	D_dice_size=6;
	Armor=3;
	StrenPts=8;
}

/*********************************************************************  
** Function: attack  
** Description: rolls the attack dice and keeps track of hits, with a
**				5% chance that 3d6 is rolled instead of 1d6
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of hits is returned
*********************************************************************/
int Gollum::attack(){
	int hits=0;
	int temp;
	int ring=rand()%20;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~GOLLUM ATTACK~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	if(ring==0){
		cout<<"Gollum's power of the RING has been activated. He will now roll 3d6 instead of 1d6."<<endl;
		for(int i=0; i<3; i++){
			temp=rand()%A_dice_size+1;
			cout<<"Roll "<<i<<": "<<temp<<endl;
			hits=hits+temp;
		}
	}
	else{
		for(int i=0; i<A_num_dice; i++){
			temp=rand()%A_dice_size+1;
			cout<<"Roll "<<i<<": "<<temp<<endl;
			hits=hits+temp;
		}
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
int Gollum::defense(int damage){
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~GOLLUM DEFENSE~~~~~~~~~~~"<<endl;
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
void Gollum::printStatus(){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~GOLLUM STATUS~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Remaining Strength Points: "<<StrenPts<<endl;
}