//Tida Sooreechine
//Final Project, 12/7/15

//Voldemort.cpp is the Voldemort class function implementation file

#include "voldemort.hpp"

//Voldemort class constructor 
Voldemort::Voldemort(string name, string spell)
{
	this->name = name;
	this->spell = spell;
	attackNumDice = 3;
	attackNumSides = 6;
	defenseNumDice = 1;
	defenseNumSides = 6;
	armor = 7;
	strength = 20;
}

