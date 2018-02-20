//Tida Sooreechine
//Final Project, 12/5/15

//prefects.cpp is the Prefects class function implementation file

#include "prefects.hpp"

//Prefects class constructor
Prefects::Prefects()
{
	id = 4; 
	type = 2;
	name = "Prefects' Bathroom";
	enemy = "Moaning Myrtle";
	numSides = 10;
	taskCompleted = false;
}

void Prefects::getTask()
{
	if (!this->taskCompleted)
	{
		cout << "Bubbles, bubbles everywhere. There is a sudden explosion of awful piercing scream and loud cackles. A pale," << endl;
		cout << "bespectacled ghost pops up from the bathtub, sending splashes of soapy water all over you. Moaning Myrtle!" << endl << endl;
 
		cout << "Hermione: Harry!" << endl << endl;

		cout << "Moaning Myrtle: No! You will play a guessing game with me. If you win, you get to take her with you. But if I win..." << endl << endl;
		
		cout << "INSTRUCTION: Stop to save Hermione or turn a different direction. You will have 3 tries if you play." << endl << endl;
	}
	else
	{
		cout << "Moaning Myrtle: Oh, Harry, if you die over there, you are welcome to share my toilet in the girl's bathroom." << endl << endl;
	}
}

bool Prefects::special(int number)
{
	//this spell is similar to Creature class' defense function from Assignments 3 and 4
	int mystery = 0;
	int tries = 0;

	Die *toilet = new Die(numSides);	

	//generate Moaning Myrtle's mystery number
	mystery = toilet->roll();
	delete toilet;

	cout << "Moaning Myrtle: Harry Potter, pick a number 1-10: ";
	cin >> number;
	cout << endl;

	//handle player's wrong guess
	while (number != mystery && tries < 2)
	{
		tries++;

		if (number < mystery)
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
		else
		{
			cout << "Moaning Myrtle: Wrong! The number I'm thinking of is less than " << number << "." << endl;
			cout << "You have " << 3 - tries << " chances left. Guess gain: ";
			cin >> number;
			cout << endl;	
		}
	}
	
	if (number == mystery && tries <= 3)	//if player guesses correctly within 3 attempts
	{
		cout << "................................................................................" << endl;
		cout << "You guessed correct! You get to take Hermione with you." << endl;

		//give player a hint of where Lord Voldemort is at
		cout << "................................................................................" << endl;
		cout << "Hermione: Oh, Harry! Thank God, you're all right! Listen, I have it all" << endl;
		cout << "figured out. Voldemort is inside Dumbledore's office!" << endl;
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

