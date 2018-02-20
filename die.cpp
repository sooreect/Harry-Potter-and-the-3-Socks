//Tida Sooreechine
//Final Project, 12/5/15

//die.cpp is the Die class function implementation file.

#include "die.hpp"

Die::Die(int numSides)
{
	this->numSides = numSides;
}

int Die::roll()
{
	return (rand() % numSides + 1);
}

