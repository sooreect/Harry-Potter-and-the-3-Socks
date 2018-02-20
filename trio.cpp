//Tida Sooreechine
//Final Project, 12/7/15

//trio.cpp is the Trio class function implementation file

#include "trio.hpp"

//Trio class constructor 
Trio::Trio(string name, string spell)
{
	this->name = name;
	this->spell = spell;
	attackNumDice = 2;
	attackNumSides = 9;
	defenseNumDice = 3;
	defenseNumSides = 6;
	armor = 3;
	strength = 10;
}

