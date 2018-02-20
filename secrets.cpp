//Tida Sooreechine
//Final Project, 12/5/15

//secrets.cpp is the Secrets class function implementation file

#include "secrets.hpp"

//Secrets class constructor
Secrets::Secrets()
{
	id = 2; 
	type = 2;
	name = "Chamber of Secrets";
	enemy = "Moaning Myrtle";
	numSides = 10;
	taskCompleted = false;
}

void Secrets::getTask()
{
	if (!this->taskCompleted)
	{
		cout << "More shrilling screams and giggles, this time without the bubbles. She's here to haunt you again. Moaning Myrtle!" << endl << endl;
 
		cout << "Ron: Harry!" << endl << endl;

		cout << "Moaning Myrtle: No! You must play a guessing game with me. You can take him only if you win." << endl << endl;
		
		cout << "INSTRUCTION: Stop to save Ron or turn a different direction. You will have 3 tries if you play." << endl << endl;
	}
	else
	{
		cout << "Moaning Myrtle: Oh, Harry, if you die over there, you are welcome to share my toilet in the girl's bathroom." << endl << endl;
	}
}

bool Secrets::special(int number)
{
	int mystery2 = 0;
	int tries = 0;

	Die *toilet2 = new Die(numSides);	

	//generate Moaning Myrtle's mystery number
	mystery2 = toilet2->roll();
	delete toilet2;

	cout << "Moaning Myrtle: Harry Potter, pick a number 1-10: ";
	cin >> number;
	cout << endl;

	//handling incorrect guess
	while (number != mystery2 && tries < 2)
	{
		tries++;

		if (number < mystery2)	//if player's number is too high
		{
			cout << "Moaning Myrtle: Wrong! The number I'm thinking of is higher than " << number << "." << endl;
			cout << "You have " << 3 - tries << " ";
			if (tries == 2)
				cout << "chance";
			else
				cout << "chances";
			cout << " left. Guess gain: ";
			cin >> number;
			cout << endl;	
		}
		else //if player's number is too low
		{
			cout << "Moaning Myrtle: Wrong! The number I'm thinking of is less than " << number << "." << endl;
			cout << "You have " << 3 - tries << " ";
			if (tries == 2)
				cout << "chance";
			else
				cout << "chances";
			cout << " left. Guess gain: ";
			cin >> number;
			cout << endl;	
		}
	}

	if (number == mystery2 && tries <= 3)	//if player has guessed correctly within 3 attempts
	{
		cout << "................................................................................" << endl;
		cout << "You guessed correct! You get to take Ron with you." << endl;

		cout << "................................................................................" << endl;
		cout << "Ron: Blimey, Harry! You did bloody brilliant there!" << endl;
		cout << "................................................................................" << endl;
		
		return true;
	}
	else	
	{
		cout << "................................................................................" << endl;
		cout << "Sorry, you're on your own, Harry." << endl;
		cout << "................................................................................" << endl;
		
		return false;
	}
}

