//Tida Sooreechine
//Final Project, 12/5/15

//dumbledore.hpp is the Dumbledore class specification file

#ifndef DUMBLEDORE_HPP
#define DUMBLEDORE_HPP

#include <queue>

#include "space.hpp"
#include "hogwarts.hpp"
#include "voldemort.hpp"
#include "trio.hpp"

using std::cout;
using std::queue;

//Dumbledore class declaration
class Dumbledore : public Space
{
private:
	bool win;
	queue<Creature*> dumbledoresArmy;	

public:
	Dumbledore();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
