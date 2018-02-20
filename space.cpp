//Tida Sooreechine
//Final Project, 12/5/15

//space.cpp is the Space class function implementation file

#include "space.hpp"

int Space::getID()
{
	return id;
}

int Space::getType()
{
	return type;
}

string Space::getName()
{
	return name;
}

string Space::getEnemy()
{
	return enemy;
}

string Space::getReward()
{
	return reward;
}

void Space::setMap(Space *north, Space *east, Space *west, Space *south)
{
	this->north = north;
	this->east = east;
	this->west = west;
	this->south = south;
}

bool Space::getTaskCompleted()
{
	return taskCompleted;
}

void Space::setTaskCompleted(bool status)
{
	taskCompleted = status;
}

