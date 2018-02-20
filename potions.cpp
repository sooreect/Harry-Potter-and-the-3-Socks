//Tida Sooreechine
//Final Project, 12/5/15

//potions.cpp is the Potions class function implementation file

#include "potions.hpp"

//Potions class constructor
Potions::Potions()
{
	id = 6;
	type = 1;
	name = "Potions Classroom in the Dungeon";
	enemy = "Draco Malfoy";
	reward = "1 green sock";
	numSides = 10;
	taskCompleted = false;
}

void Potions::getTask()
{
	if (!this->taskCompleted)
	{
		cout << "You saw a flash of white, and it took your eyes almost a full minute to adjust to the darkness again." << endl;
		cout << "There's no mistaking that white face and hair. You can almost smell his arrogance in the room. Draco Malfoy!" << endl << endl;  
	
		cout << "INSTRUCTION: Duel with him and take his sock. You will have 3 tries." << endl << endl;
	}
	else
	{
		cout << "Draco Malfoy has already been defeated. Unfortunately, he was wearing just 1 sock." << endl;
		cout << "These Death Eaters and their strange habits. Let's keep going." << endl << endl;
	}
}

bool Potions::special(int number)
{
	//this function is similar to Creature class' defense function from Assignments 3 and 4
	int spell = 0;

	Die *serpensortia = new Die(numSides);	

	//enemy attacks
	spell = serpensortia->roll();
	delete serpensortia;

	//determine winner
	if (spell > number)
	{
		//if enemy's roll is higher, the spell is casted first
		cout << this->enemy << ": Serpensortia! (" << spell << ")" << endl;
		cout << "You: Sectum Sempra! (" << number << ")" << endl;
	
		return false;
	}
	else if (spell == number)
	{
		//if it's a tie, let player win
		cout << "You: Sectum Sempra! (" << (number + 1) << ")" << endl;
		cout << this->enemy << ": Sorpensortia! (" << spell << ")" << endl << endl;

		usleep(1000000);	//pause 1 second

		cout << this->enemy << ": Ugh, my father will hear about this, Potter!" << endl;

		return true;
	}
	else
	{
		//else, player's spell is casted first	
		cout << "You: Sectum Sempra! (" << number << ")" << endl;
		cout << this->enemy << ": Sorpensortia! (" << spell << ")" << endl << endl;
	
		usleep(1000000);	//pause 1 second

		cout << this->enemy << ": Ugh, my father will hear about this, Potter!" << endl;
		
		return true;
	}
}

