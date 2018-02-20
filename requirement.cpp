//Tida Sooreechine
//Final Project, 12/5/15

//requirement.cpp is the Requirement class function implementation file

#include "requirement.hpp"

//Requirement class constructor
Requirement::Requirement()
{
	id = 5;
	type = 1;
	name = "Room of Requirement";
	enemy = "Argus Filch";
	reward = "1 pink sock";
	numSides = 10;
	taskCompleted = false;
}

void Requirement::getTask()
{
	if (!this->taskCompleted)
	{
		cout << "You see a lamp glow from a distance, accompanied by low growling and unpleasant purring. Hogwarts' creepy" << endl;
		cout << "squib caretaker, he must have stumbled in here while trying to catch students out of bed. Argus Filch!" << endl << endl; 
	
		cout << "INSTRUCTION: Duel with him and Mrs. Norris, his cat, to win his sock. You will have 3 tries." << endl << endl;
	}
	else
	{
		cout << "Filch has already been defeated. Unfortunately, he was wearing just 1 sock." << endl;
		cout << "Yes, him too." << endl << endl;
	}
}

bool Requirement::special(int number)
{
	//this function is similar to Creature class' defense function from Assignments 3 and 4
	int cursing = 0;

	Die *mrsNorris = new Die(numSides);	

	//enemy attacks
	cursing = mrsNorris->roll();
	delete mrsNorris;

	//determine winner
	if (cursing > number)
	{
		//if enemy's roll is higher
		cout << this->enemy << ": Professor Umbridge! Student out of bed! (" << cursing << ")" << endl;
		cout << "You: Stupefy! (" << number << ")" << endl;
	
		return false;
	}
	else if (cursing == number)
	{
		//if it's a tie, let player win
		cout << "You: Stupefy! (" << (number + 1) << ")" << endl;
		cout << this->enemy << ": * silence *  (" << cursing << ")" << endl;

		return true;
	}
	else
	{
		//else, player's spell is casted first	
		cout << "You: Stupefy! (" << number << ")" << endl;
		cout << this->enemy << ": * silence * (" << cursing << ")" << endl;
		
		return true;
	}
}

