//Tida Sooreechine
//Final Project, 12/7/15

//creature.hpp is the Creature class specification file

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <iomanip>
#include <unistd.h>

#include "die.hpp"

using std::cout;
using std::endl;
using std::string;
using std::setw;

//Creature class declaration
class Creature
{
protected:
	string name;
	string spell;
	int attackNumDice;
	int attackNumSides;
	int defenseNumDice;
	int defenseNumSides;
	int armor;
	int strength;

public:
	string getName();
	string getSpell();
	int getStrength();
	int attack();
	int defense(int attackReceived);
};

#endif
