//Tida Sooreechi
//Final Project, 12/5/15

//potter.cpp is the Potter class function implementation file

#include "potter.hpp"

Potter::Potter()
{
	alive = true;
	ron = false;
	hermione = false;
	wins = 0;
}

void Potter::setDead()
{
	alive = false;
}

bool Potter::getStatus()
{
	return alive;
}

bool Potter::getRon()
{
	return ron;
}

void Potter::setRon(bool friend1)
{
	ron = friend1;
}

bool Potter::getHermione()
{
	return hermione;
}

void Potter::setHermione(bool friend2)
{
	hermione = friend2;
}

void Potter::addSock(string sock)
{
	unsigned int capacity = 3;
	
	if (bag.size() != capacity)
	{
		bag.push_back(sock);
	}
	else 
	{
		cout << "Error! You have enough socks to set the elves free! You don't need this. Hurry!" << endl << endl;
	}	
}

int Potter::getNumSocks()
{
	return bag.size();
}

int Potter::play(int max)
{
	int score = 0;
	Die *hpDie = new Die(max);
	score = hpDie->roll();

	delete hpDie;
	return score;	
}

int Potter::getWins()
{
	return wins;
}

void Potter::setWins()
{
	wins++;
}
