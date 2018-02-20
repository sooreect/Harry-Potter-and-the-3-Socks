//Tida Sooreechine
//Final Project, 12/5/15

//hogwarts.cpp is the Hogwarts class function implementation file

#include "hogwarts.hpp"

Hogwarts::Hogwarts()
{
	//create space objects
	harry = new Potter();
	space1 = new Gryffindor();
	space2 = new Secrets();
	space3 = new Dada();
	space4 = new Prefects();
	space5 = new Requirement();
	space6 = new Potions();
	space7 = new Dumbledore();
	
	//set initial location at Gryffindor Common Room
	location = space1;	

	//build Hogwarts
	space1->setMap(space4, space3, NULL, NULL);
	space2->setMap(NULL, space4, NULL, NULL);
	space3->setMap(space6, NULL, space1, NULL);
	space4->setMap(NULL, space6, space2, space1);
	space5->setMap(NULL, NULL, space6, NULL);
	space6->setMap(space7, space5, space4, space3);
	space7->setMap(NULL, NULL, NULL, space6);
}

void Hogwarts::printGameInfo()
{
	cout << "FINAL PROJECT: HARRY POTTER AND THE THREE SOCKS" << endl << endl << endl;

	usleep(1000000);	//pause 1 second

	cout << "You wake up and find yourself alone in the Gryffindor Common Room. One glance is all it takes for you to register" << endl;
	cout << "that something is terribly wrong. Objects all around you are broken and scattered. The only thing that seems to be" << endl;
	cout << "alive is the fire in the fireplace." << endl << endl;

	cout << "Dumbledore: Harry..." << endl << endl;
 
	cout << "You hear Professor Dumbledore’s voice, but where is it coming from? You don’t see him anywhere." << endl << endl;
	
	cout << "You: Professor? What, what happened here, sir?" << endl << endl;
 
    cout << "Dumbledore: Harry, Voldemort had made his way into Hogwarts and had taken 3 captives. You will need to find him and" << endl;
	cout << "you will need to finish him, once and for all. Also, take 3 socks with you. You will need them to free Kreacher," << endl;
	cout << "Winky, and Dobby. No other articles of clothing will do. When in doubt, ask your friends." << endl << endl;
 
	cout << "You: But, sir, where are Ron and Hermione?" << endl << endl;
 
	cout << "Dumbledore: Miss Granger and Mr. Weasley have been taken as prisoners as well. Their presence will not be required" << endl;
	cout << "to finish the task at hand. You will have 1 hour to do so. I must go now. Good luck, Harry." << endl << endl;
 
	cout << "You: Professor, wait, Professor Dumbledore!" << endl << endl;

	cout << "Silence. The game has begun." << endl << endl << endl;
}

void Hogwarts::printSpaceInfo(double minutes)
{
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Room " << location->getID() << ": " << location->getName() << endl;
	cout << "Socks Acquired = " << harry->getNumSocks() << endl;

	if (harry->getRon() && harry->getHermione())
		cout << "* Ron and Hermione are right beside you." << endl;
	else if (harry->getRon())
 		cout << "* Ron is right behind you." << endl;
	else if (harry->getHermione())
 		cout << "* Hermione is right behind you." << endl;
	cout << "Countdown: " << (60 - minutes) << " Minutes" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void Hogwarts::printMenuAction()
{
	if (!location->getTaskCompleted())
	{
		cout << "Options:" << endl;

		cout << " [1] ";
		if (location->getType() == 1)
			cout << "Fight " << location->getEnemy() << endl;
		else if (location->getType() == 2)
			cout << "Play a guessing game with " << location->getEnemy() << endl;

		cout << " [2] Run!" << endl;
	}
	else
	{
		cout << "Option:" << endl;
		cout << " [2] Keep going" << endl;
	}
}

void Hogwarts::printMenuDirection()
{
	cout << "Directions:" << endl;

	cout << " [1] Go North";
	if (location->north != NULL)
		cout << " - " << location->north->getName();
	cout << endl;

	cout << " [2] Go East"; 
	if (location->east != NULL)
		cout << " - " << location->east->getName();
	cout << endl;

	cout << " [3] Go West";
	if (location->west != NULL)
		cout << " - " << location->west->getName();
	cout << endl;

	cout << " [4] Go South";
	if (location->south != NULL)
		cout << " - " << location->south->getName();
	cout << endl;
}

