//Tida Sooreechine
//Final Project, 12/5/15

//dumbledore.cpp is the Dumbledore class function implementation file

#include "dumbledore.hpp"

//Dumbledore class constructor
Dumbledore::Dumbledore()
{
	id = 7; 
	type = 3;
	name = "Dumbledore's Office";
	enemy = "Lord Voldemort";
	numSides = 10;
	taskCompleted = false;
	win = false;
}

void Dumbledore::getTask()
{
	cout << "At long last." << endl << endl;

	usleep(2000000);	//pause 2 seconds

	cout << "Lord Voldemort: Harry Potter, the Boy Who lived... come to die." << endl << endl;

	usleep(2000000);	//pause 2 seconds

	cout << "He raises his wand..." << endl; 

	usleep(2000000);	//pause 2 seconds
}

bool Dumbledore::special(int number)
{
	int attackValue, defenseValue;
	Creature *fighter1, *fighter2;	

	//instantiate Lord Voldemort
	fighter2 = new Voldemort("Voldemort", "Avada Kedavra!");

	//create another instance of Harry (just for fighting) and his friends
	//input each character in a fighting queue - FIFO
	if (number == 1)
	{
		Creature *character1 = new Trio("You", "Expelliarmus!");
		dumbledoresArmy.push(character1);
	}
	else if (number == 2)
	{
		Creature *character1 = new Trio("You", "Expelliarmus!"); 
	 	Creature *character2 = new Trio("Ron", "Diffindo!");
		dumbledoresArmy.push(character1);
		dumbledoresArmy.push(character2);	
	}
	else if (number == 3)
	{
		Creature *character1 = new Trio("You", "Expelliarmus!");
		Creature *character2 = new Trio("Hermione", "Pretificus Totalus!");
		dumbledoresArmy.push(character1);
		dumbledoresArmy.push(character2);
	}
	else 
	{
		Creature *character1 = new Trio("You", "Expelliarmus!");
		Creature *character2 = new Trio("Ron", "Diffindo!");
		Creature *character3 = new Trio("Hermione", "Petrificus Totalus!");
		dumbledoresArmy.push(character1);
		dumbledoresArmy.push(character2);
		dumbledoresArmy.push(character3);
	}

	//the final battle
	for (int battle = 0; battle < 100; battle++)
	{
		//if both sides are still alive
		if ((!dumbledoresArmy.empty()) && (fighter2->getStrength() > 0)) 
		{
			//naming the first trio member in line as fighter
			fighter1 = dumbledoresArmy.front(); 
			
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "Round " << (battle + 1) << " : ";
			cout << fighter1->getName() << " [" << fighter1->getStrength() << "] VS. ";
			cout << fighter2->getName() << " [" << fighter2->getStrength() << "]" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;

			//fighter1 attacks 
			attackValue = fighter1->attack();
			cout << fighter1->getName() << ": " << fighter1->getSpell() << " (" << attackValue << ")" << endl;
			
			//Voldemort defends
			defenseValue = fighter2->defense(attackValue);
			cout << fighter2->getName() << ": " << fighter2->getSpell() << " (" << defenseValue << ")" << endl;
		
			//if Voldemort is still alive, he attacks back	
			if (fighter2->getStrength() > 0)
			{
				cout << "." << endl;
				attackValue = fighter2->attack();
				cout << fighter2->getName() << ": " << fighter2->getSpell() << " (" << attackValue << ")" << endl;
							
				//fighter1 defends
				defenseValue = fighter1->defense(attackValue);
				cout << fighter1->getName() << ": " << fighter1->getSpell() << " (" << defenseValue << ")" << endl;
				
				//check if fighter1 is injured
				if (fighter1->getStrength() <= 0)	
				{
					if (fighter1->getName() == "You")
						cout << fighter1->getName() << "are too injured to continue!" << endl;
					else
						cout << fighter1->getName() << "is too injured to continue!" << endl;

					dumbledoresArmy.pop();
				}
				else
				{
					//if fighter1's strength is greater than 0, put him/her back at the end of queue
					dumbledoresArmy.pop();
					dumbledoresArmy.push(fighter1);
					if (!dumbledoresArmy.empty())
					{
						fighter1 = dumbledoresArmy.front();
					}
				}
			}
			else
			{
				cout << endl;
				cout << "Lord Voldemort is dead." << endl << endl;	
			}
			usleep(1000000);	//pause 1 second
		}
	}

	delete fighter2; 

	if (!dumbledoresArmy.empty())	//if harry and friends are still alive
		return true;
	else	
		return false;
}	

