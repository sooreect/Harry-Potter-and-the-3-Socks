//Tida Sooreechine
//Final Project, 12/5/15

//gryffindor.cpp is the Gryffindor class function implementation file

#include "gryffindor.hpp"

//Gryffindor class constructor
Gryffindor::Gryffindor()
{
	id = 1;
	type = 1;
	name = "Gryffindor Common Room";
	enemy = "Bellatrix Lestrange";
	reward = "1 purple sock";
	numSides = 10;
	taskCompleted = false;
}

void Gryffindor::getTask()
{
	if (!this->taskCompleted)	//display the following message if task has not been completed
	{
		cout << "Running footsteps, maniacal laughter. A deranged woman with wild, black hair steps out from behind the couch." << endl;
		cout << "You can recognize those heavy-lidded eyes anywhere. Bellatrix Lestrange!" << endl << endl; 
	
		cout << "INSTRUCTION: Duel with her and take her sock. You will have 3 tries." << endl << endl;
	}
	else	//display the following mssage if task has already been met
	{
		cout << "Bellatrix Lestrange has already been defeated. Unfortunately, she was wearing just 1 sock." << endl;
		cout << "Very strange, indeed, but there is nothing left to do here." << endl << endl;
	}
}

bool Gryffindor::special(int number)
{
	//this function is similar to Creature class' defense function from Assignments 3 and 4
	int spell = 0;

	Die *crucio = new Die(numSides);	

	//enemy attacks
	spell = crucio->roll();
	delete crucio;

	//determine winner
	if (spell > number)
	{
		//if enemy's roll is higher, the spell is casted first
		cout << this->enemy << ": Crucio! (" << spell << ")" << endl;
		cout << "You: Stupefy! (" << number << ")" << endl;
	
		return false;
	}
	else if (spell == number)
	{
		//if it's a tie, let player win
		cout << "You: Stupefy! (" << (number + 1) << ")" << endl;
		cout << this->enemy << ": Crucio! (" << spell << ")" << endl;

		return true;
	}
	else
	{
		//else, player's spell is casted first	
		cout << "You: Stupefy! (" << number << ")" << endl;
		cout << this->enemy << ": Crucio! (" << spell << ")" << endl;
		
		return true;
	}
}

