//Tida Sooreechine
//Final Project, 12/5/15

//space.hpp is the Space class specification file

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>

#include "die.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Space class declaration
class Space
{
protected:
	int id;
	int type;
	string name;
	string enemy;
	string task;
	string reward;
	int numSides;
	bool taskCompleted;

public:
	Space *north;
	Space *east;
	Space *west;
	Space *south;
	int getID();
	int getType();
	string getName();
	string getEnemy();
	string getReward();
	void setMap(Space *north, Space *east, Space *west, Space *south);
	virtual void getTask() = 0;
	virtual bool special(int number) = 0;
	bool getTaskCompleted();
	void setTaskCompleted(bool status);
};

#endif
