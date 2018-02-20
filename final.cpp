/**************************************************************************************************
 * Program Filename: final.cpp
 * Author: Tida Sooreechine
 * Date: 12/5/2015
 * Description: A Harry Potter game intended for the player to collect three socks, save his
 * 	friends, and fight Lord Voldemort. 
 * Inputs: Player specifies choices of action, direction, and whatever input required to succeed 
 * 	the specific tasks. 
 * Outputs: The outcomes of the game.
**************************************************************************************************/

#include <iostream>
#include <cstdlib>		//header file needed to use srand and rand
#include <ctime>		//header file needed to use time
#include <chrono>		//header file needed to set the game timer
#include <unistd.h>		//header file needed to use usleep
#include <cmath>		//header file needed to use 

#include "hogwarts.hpp"

using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

int main()
{
	char choice;	

	do
	{
		system("clear");	//clear screen

		srand(time(NULL));	//set the random generator seed 

		//declaring local variables
		int action, direction;
		int elapsed = 0;
		int hpNumber = 0;
		bool na1, na2, na3, na4, input;

		//create Hogwarts School of Witchcraft and Wizardry
		Hogwarts *hogwarts = new Hogwarts();
	
		hogwarts->printGameInfo();
		usleep(3000000);    //pause 3 seconds

		//prompt user to proceed
		cout << "Would you like to play? [Y/N]: ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			//start timer
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			//Source: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/

			//game continues as long as harry is alive and time elapsed is under 1 hour
			while (hogwarts->harry->getStatus() && elapsed < 60)
			{ 		
				//get elapsed time when entering a space
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
				elapsed = ceil(time_span.count() / 60);
		
				//print space's info and task
				hogwarts->printSpaceInfo(elapsed);	
				hogwarts->location->getTask();

				usleep(2000000);	//pause 2 seconds

				hogwarts->printMenuAction();
				cout << "Action = ";
				cin >> action;

				//if this is a new room
				if (!hogwarts->location->getTaskCompleted())
				{
					while (action < 1 || action > 2)
					{
						cout << "Invalid input. Please enter 1 or 2: ";
						cin >> action;
					}
					cout << endl;
	
					//if socks room (space 1, 3, 5, or 6)
					if (hogwarts->location->getType() == 1)
					{
						//if player chooses to fight opponent
						if (action == 1)
						{
							for (int round = 0; round < 3; round++)
							{
								//if task has not been completed, allow player 3 attempts
								if (!hogwarts->location->getTaskCompleted())
								{		
									hpNumber = hogwarts->harry->play(10);
							
									//if player wins
									if (hogwarts->location->special(hpNumber))
									{
										cout << endl;
										hogwarts->location->setTaskCompleted(true);
										hogwarts->harry->setWins();	
										cout << "You win!" << endl;
									}
									cout << endl;
								}
								
								usleep(1000000);	//pause 1 second
							}

							//display message based on whether or not player has defeated the space enemy
							if (!hogwarts->location->getTaskCompleted())
							{
								cout << "................................................................................" << endl;
								cout << "That last attack was too much to handle. The Boy Who Lived is now dead." << endl;
								cout << "................................................................................" << endl;
								cout << "You lose!" << endl << endl;
	
								cout << "G A M E  O V E R" << endl;
								cout << "................................................................................" << endl << endl;
								hogwarts->harry->setDead();	
							}	
							else
							{
								cout << "................................................................................" << endl;
								cout << "Congratulations, Harry! You've won yourself " << hogwarts->location->getReward() << "!" << endl;
								hogwarts->harry->addSock(hogwarts->location->getReward());
								cout << "You are one step closer to finishing Lord Voldemort!" << endl;
						
								if (hogwarts->harry->getWins() == 3)
								{
									cout << "................................................................................" << endl;
									cout << "Well done! You found yourself 3 socks!" << endl;
								}
								cout << "................................................................................" << endl << endl;
								usleep(2000000);	//pause 2 seconds
							}
						}
					}
					//if Moaning Myrtle room (space 2 or 4)
					else if (hogwarts->location->getType() == 2)
					{
						//if player chooses to play the guessing game
						if (action == 1)
						{
							//if player defeats Moaning Myrtle in space 2, take Ron 
							if(hogwarts->location->getID() == 2 && hogwarts->location->special(0))
							{
								hogwarts->harry->setRon(true);
							}

							//if player defeats Moaning Myrtle in space 4, take Hermione
							if(hogwarts->location->getID() == 4 && hogwarts->location->special(0))
							{
								hogwarts->harry->setHermione(true);
							}
							hogwarts->location->setTaskCompleted(true);
						}						
						cout << endl;
					}					
				}	
				else	//old room, task has been completed
				{
					while (action != 2)
					{
						cout << "Invalid input. Please enter 2: ";
						cin >> action;
					}
					cout << endl;
				}

				//if player is still alive after facing the enemy, prompt user for new space entry
				if (hogwarts->harry->getStatus())
				{
					hogwarts->printMenuDirection();		
					cout << "Direction = ";
					cin >> direction;
					while (direction < 1 || direction > 4)
					{
						cout << "Invalid input. Please enter 1-4: ";
						cin >> direction;
						cout << endl;
					}
					cout << endl;

					//handle NULL spaces
					na1 = na2 = na3 = na4 = input = false;
					if (hogwarts->location->north == NULL && direction == 1)
						na1 = true;
					else if (hogwarts->location->east == NULL && direction == 2)
						na2 = true;
					else if (hogwarts->location->west == NULL && direction == 3)
						na3 = true;
					else if (hogwarts->location->south == NULL && direction == 4)
						na4 = true;
				
					//display error message if player chooses to access NULL spaces
					if (na1 || na2 || na3 || na4)
					{
						cout << "Impossible. That area is inaccessible to students at this hour." << endl << endl;
						cout << "Try again: ";
						do	
						{
							cin >> direction;

							na1 = na2 = na3 = na4 = input = false;
							if (hogwarts->location->north == NULL && direction == 1)
								na1 = true;
							else if (hogwarts->location->east == NULL && direction == 2)
								na2 = true;
							else if (hogwarts->location->west == NULL && direction == 3)
								na3 = true;
							else if (hogwarts->location->south == NULL && direction == 4)
								na4 = true;
				
							if (direction < 1 || direction > 4 || na1 || na2 || na3 || na4)
								cout << "Invalid input. Please try again: ";
							else
								input = true;
						} while (!input);
						cout << endl << endl;
					}
					
					//if player has chosen an accessible space to enter, direct player to new room
					if (direction == 1)
					{		
						cout << "Entering " << hogwarts->location->north->getName() << "..." << endl << endl;
						hogwarts->location = hogwarts->location->north;
					}
					else if (direction == 2)
					{		
						cout << "Entering " << hogwarts->location->east->getName() << "..." << endl << endl;
						hogwarts->location = hogwarts->location->east;
					}
					else if (direction == 3)
					{		
						cout << "Entering " << hogwarts->location->west->getName() << "..." << endl << endl;
						hogwarts->location = hogwarts->location->west;
					}
					else
					{		
						cout << "Entering " << hogwarts->location->south->getName() << "..." << endl << endl;
						hogwarts->location = hogwarts->location->south;
					}

					usleep(1500000);	//pause 1.5 seconds for dramatic effect

					//if player chooses to enter the final battle room
					if (hogwarts->location->getID() == 7)
					{
						//display error message if player does not have the required number of socks
						if (hogwarts->harry->getNumSocks() != 3)
						{
							cout << "................................................................................" << endl;
							cout << "You are not ready to face Voldemort yet, you need more socks!" << endl;
							cout << "................................................................................" << endl << endl;

							cout << "Option:" << endl;
							cout << " [2] Move along" << endl;
							cout << "Action = ";
							cin >> action;
							while (action != 2)
							{
								cout << "Invalid input. Please enter 2: ";
								cin >> action;
							}
							cout << endl;
						
							//take player back to space 6
							cout << "Retreating back to " << hogwarts->location->south->getName() << "..." << endl << endl;
							hogwarts->location = hogwarts->location->south;

							usleep(1500000);	//pause 1.5 seconds
						}
						else
						{
							//get elapsed time
							high_resolution_clock::time_point t2 = high_resolution_clock::now();
							duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
							elapsed = ceil(time_span.count() / 60);

							hogwarts->printSpaceInfo(elapsed);
							hogwarts->location->getTask();

							//check which friends are present and send that information to Dumbledore class
							//so that the correct objects can be instantiated
							if (hogwarts->harry->getRon() && hogwarts->harry->getHermione())
								hpNumber = 4;
							else if (hogwarts->harry->getHermione())
								hpNumber = 3;
							else if (hogwarts->harry->getRon())
								hpNumber = 2;
							else 
								hpNumber = 1;
						
							//if harry potter wins
							if (hogwarts->location->special(hpNumber))
							{
								usleep(2000000);	//pause 2 seconds

								cout << "................................................................................" << endl;
								cout << "Dobby: Harry Potter is valiant and bold! He has braved so many dangers today!" << endl;
								cout << "Now Dobby has got a sock. Dobby is free!" << endl << endl;
			
								cout << "Dumbledore: Thank you, Harry. For pure nerve and outstanding courage, I award" << endl;
								cout << "Gryffindor house 60 points." << endl << endl;
 
								cout << "All is well." << endl;
								cout << "................................................................................" << endl;
								cout << "You win!" << endl << endl;

								cout << "G A M E  O V E R" << endl;
								cout << "................................................................................" << endl << endl;
								hogwarts->harry->setDead();	//he's not dead, this is just to end the game
							}			
							else //if harry potter loses
							{
								hogwarts->harry->setDead();
								cout << "................................................................................" << endl;
								cout << "You lose!" << endl << endl;

								cout << "G A M E  O V E R" << endl;
								cout << "................................................................................" << endl << endl;
							}
						}
					}
				}
			}
		}
	
		delete hogwarts;

		//give the player the option to play again	
		cout << "Would you like to play again? [Y/N]: ";
		cin >> choice;	
	} while (choice == 'y' || choice == 'Y');

	cout << endl << endl;

	return 0;
}

