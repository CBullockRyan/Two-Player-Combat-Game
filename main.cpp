/*********************************************************************  
** Program Filename: main.cpp
** Author: Cassidy Bullock    
** Date: 7/18/2016  
** Description: Conducts a player versus player dice game utilizing
**				classes, inheritance, and polymorphism.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Medusa.h"
#include "Gollum.h"
#include "Reptile.h"
#include "Blue.h"
#include "Potter.h"
using namespace std;

/*********************************************************************  
** Function: printOptions  
** Description: displays character choice options
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: character menu printed
*********************************************************************/
void printOptions(){
	cout<<"Please choose your fighter:"<<endl;
	cout<<"1. Medusa"<<endl;
	cout<<"2. Gollum"<<endl;
	cout<<"3. Reptile People"<<endl;
	cout<<"4. Blue Men"<<endl;
	cout<<"5. Harry Potter"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Enter 1, 2, 3, 4, or 5: ";
}

/*********************************************************************  
** Function: getChoice  
** Description: gets user choice of character
** Parameters: string for which player it is
** Pre-Conditions: none
** Post-Conditions: user choice is returned as an int
*********************************************************************/
int getChoice(string player){
	int choice;
	cout<<"~~~~~~~~~~~"<<player<<"~~~~~~~~~~"<<endl;
	printOptions();
	cin>>choice;
	return choice;
}

/*********************************************************************  
** Function: run
** Description: executes rounds of battle between players
** Parameters: pointers to player objects, hits, damage
** Pre-Conditions: both players must be defined
** Post-Conditions: goes until one player dies
*********************************************************************/
void run(Character *player1, Character *player2, int hits, int damage){
	int temp=1;
	int ctr=1;
	while(temp=1){
		cout<<"~~~~~~~~~~~ROUND "<<ctr<<"~~~~~~~~~~~~"<<endl;
		hits=player1->attack();
		if(hits==900){
			cout<<"Player1: Medusa has used the GLARE power and turned Player2 to stone. Congradulations Player1."<<endl;
			break;
		}
		damage=player2->defense(hits);
		player2->updateStrenPts(damage);
		if(player2->checkDead()){
			cout<<"Player 2 has lost. Congradulations Player 1."<<endl;
			break;
		}
		hits=player2->attack();
		if(hits==900){
			cout<<"Player2: Medusa has used the GLARE power and turned Player1 to stone. Congradulations Player2."<<endl;
			break;
		}
		damage=player1->defense(hits);
		player1->updateStrenPts(damage);
		if(player1->checkDead()){
			cout<<"Player 1 has lost. Congradulations Player 2."<<endl;
			break;
		}
		cout<<"PLAYER 1:"<<endl;
		player1->printStatus();
		cout<<"PLAYER 2:"<<endl;
		player2->printStatus();
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl<<endl;
		ctr++;
	}
}

/*********************************************************************  
** Function: createGame
** Description: takes character choice and passes correct characters into
**				the run function
** Parameters: user choice (int) and Character objects, hits and damage
** Pre-Conditions: must have user input choices
** Post-Conditions: game will be created and run
*********************************************************************/
void createGame(int choice1, int choice2, Character *player1, Character *player2, Character *player3, Character *player4, Character *player5, Character *player6, Character *player7, Character *player8, Character *player9, Character *player0, int hits, int damage){
	if(choice1==1){
		if(choice2==1){
			run(player1, player2, hits, damage);
		}
		else if(choice2==2){
			run(player1, player4, hits, damage);
		}
		else if(choice2==3){
			run(player1, player6, hits, damage);
		}
		else if(choice2==4){
			run(player1, player8, hits, damage);
		}
		else if(choice2==5){
			run(player1, player0, hits, damage);
		}
	}
	else if(choice1==2){
		if(choice2==1){
			run(player3, player2, hits, damage);
		}
		else if(choice2==2){
			run(player3, player4, hits, damage);
		}
		else if(choice2==3){
			run(player3, player6, hits, damage);
		}
		else if(choice2==4){
			run(player3, player8, hits, damage);
		}
		else if(choice2==5){
			run(player3, player0, hits, damage);
		}
	}
	else if(choice1==3){
		if(choice2==1){
			run(player5, player2, hits, damage);
		}
		else if(choice2==2){
			run(player5, player4, hits, damage);
		}
		else if(choice2==3){
			run(player5, player6, hits, damage);
		}
		else if(choice2==4){
			run(player5, player8, hits, damage);
		}
		else if(choice2==5){
			run(player5, player0, hits, damage);
		}
	}
	else if(choice1==4){
		if(choice2==1){
			run(player7, player2, hits, damage);
		}
		else if(choice2==2){
			run(player7, player4, hits, damage);
		}
		else if(choice2==3){
			run(player7, player6, hits, damage);
		}
		else if(choice2==4){
			run(player7, player8, hits, damage);
		}
		else if(choice2==5){
			run(player7, player0, hits, damage);
		}
	}
	else if(choice1==5){
		if(choice2==1){
			run(player9, player2, hits, damage);
		}
		else if(choice2==2){
			run(player9, player4, hits, damage);
		}
		else if(choice2==3){
			run(player9, player6, hits, damage);
		}
		else if(choice2==4){
			run(player9, player8, hits, damage);
		}
		else if(choice2==5){
			run(player9, player0, hits, damage);
		}
	}
}

int main(){
	srand(time(NULL));
	Medusa medus1, medus2;
	Gollum gollu1, gollu2;
	Reptile repti1, repti2;
	Blue bluem1, bluem2;
	Potter harry1, harry2;
	Character *player1=&medus1;
	Character *player2=&medus2;
	Character *player3=&gollu1;
	Character *player4=&gollu2;
	Character *player5=&repti1;
	Character *player6=&repti2;
	Character *player7=&bluem1;
	Character *player8=&bluem2;
	Character *player9=&harry1;
	Character *player0=&harry2;
	int choice1, choice2, hits, damage;
	choice1=getChoice("PLAYER 1");
	choice2=getChoice("PLAYER 2");
	createGame(choice1, choice2, player1, player2, player3, player4, player5, player6, player7, player8, player9, player0, hits, damage);
}