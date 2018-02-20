//Tida Sooreechine
//Final Project, 12/5/15

//dada.cpp is the Dada class function implementation file

#include "dada.hpp"

//class constructor
Dada::Dada()
{
	id = 3;
	type = 1;
	name = "Classroom 3C, Defense Against the Dark Arts";
	enemy = "Peter Pettigrew";
	reward = "1 orange sock";
	numSides = 10;
	taskCompleted = false;
}

void Dada::getTask()
{
	if (!this->getTaskCompleted())
	{
		cout << "You hear a high-pitch squeaking sound from behind. You turn around to face a giant rat. No, that's not it." << endl;
		cout << "It's a balding man with a rat-like face. Peter Pettigrew!" << endl << endl;
	
		cout << "INSTRUCTION: Duel with him and take his sock. You will have 3 tries." << endl << endl;
	}
	else
	{
		cout << "Peter Pettigrew has already been defeated. Unfortunately, he was wearing just 1 sock." << endl;
		cout << "You wouldn't want another one from him anyway, gross! Let's go." << endl << endl; 
	}
}

bool Dada::special(int number)
{
	//this function is similar to Creature class' defense function from Assignments 3 and 4
	int spell = 0;

	Die *reducto = new Die(numSides);	

	//enemy attacks
	spell = reducto->roll();
	delete reducto;

	if (spell > number)
	{
		//if enemy's roll is higher, their spell is casted first
		cout << this->enemy << ": Imperio! (" << spell << ")" << endl;
		cout << "You: Stupefy! (" << number << ")" << endl;

		return false;
	}
	else if (spell == number)
	{
		//if it's a tie, let player win
		cout << "You: Stupefy! (" << (number + 1) << ")" << endl;
		cout << this->enemy << ": Imperio! (" << spell << ")" << endl;

		return true;
	}
	else
	{
		//else, player's spell was casted first
		cout << "You: Stupefy! (" << number << ")" << endl;
		cout << this->enemy << ": Imperio! (" << spell << ")" << endl;

		return true;
	}
}

