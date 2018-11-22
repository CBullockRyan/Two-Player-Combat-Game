/*********************************************************************  
** Program Filename: Blue.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: This is a derived class for the Blue Men
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Blue.h"
using namespace std;

/*********************************************************************  
** Function: Blue  
** Description: constructor sets values specific to this character
** Parameters: string for which player it is
** Pre-Conditions: none
** Post-Conditions: object is initialized
*********************************************************************/
Blue::Blue(){
	A_num_dice=2;
	A_dice_size=10;
	D_num_dice=3;
	D_dice_size=6;
	Armor=3;
	StrenPts=12;
}

/*********************************************************************  
** Function: attack  
** Description: rolls the attack dice and keeps track of hits
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of hits is returned
*********************************************************************/
int Blue::attack(){
	int hits=0;
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~BLUE MEN ATTACK~~~~~~~~~~~~~~"<<endl;
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
int Blue::defense(int damage){
	int temp;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~BLUE MEN DEFENSE~~~~~~~~~~~~~~"<<endl;
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
void Blue::printStatus(){
	if(StrenPts<=8 && StrenPts>4){
		D_num_dice=2;
	}
	else if(StrenPts<=4 && StrenPts>0){
		D_num_dice=1;
	}
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~BLUE MEN STATUS~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Number of Defense Dice: "<<D_num_dice<<endl;
	cout<<"Remaining Strength Points: "<<StrenPts<<endl;
}