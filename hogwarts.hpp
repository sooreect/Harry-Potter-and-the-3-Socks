//Tida Sooreechine
//Final Project, 12/5/15

//hogwarts.hpp is the Hogwarts class specification file

#ifndef HOGWARTS_HPP
#define HOGWARTS_HPP

#include "potter.hpp"
#include "space.hpp"
#include "gryffindor.hpp"
#include "secrets.hpp"
#include "dada.hpp"
#include "prefects.hpp"
#include "requirement.hpp"
#include "potions.hpp"
#include "dumbledore.hpp"

//Hogwarts class declaration
class Hogwarts 
{
private:

public:
	Potter *harry;
	Space *space1;
	Space *space2;
	Space *space3;
	Space *space4;
	Space *space5;
	Space *space6;
	Space *space7;
	Space *location;

	Hogwarts();
	void printGameInfo();
	void printSpaceInfo(double minutes);
	void printMenuAction();
	void printMenuDirection();
};
#endif
