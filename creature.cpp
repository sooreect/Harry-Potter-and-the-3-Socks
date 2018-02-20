//Tida Sooreechine
//Final Project, 12/7/15

//creature.cpp is the Creature class function implementation file

#include "creature.hpp"

string Creature::getName()
{
	return name;
}

string Creature::getSpell()
{
	return spell;
}

int Creature::getStrength()
{
	return strength;
}

int Creature::attack()
{
	int attackPoints = 0;

	//roll the attack dice
	Die *dieA;
	dieA = new Die(attackNumSides);
	for (int i = 0; i < attackNumDice; i++)
		attackPoints += dieA->roll();
	delete dieA;
	
	return attackPoints;
}

int Creature::defense(int attackReceived)
{
	int defensePoints = 0;
	int damage = 0;	
	
	//roll the defense dice
	Die *dieD;
	dieD = new Die(defenseNumSides);
	for (int i = 0; i < defenseNumDice; i++)
		defensePoints += dieD->roll();
	
	damage = attackReceived - defensePoints - armor;

	if (damage < 0)	//cannot have negative damage
		damage = 0;

	strength -= damage;

	if (strength < 0)	//cannot have negative strength
		strength = 0;

	delete dieD;

	return defensePoints;
}

