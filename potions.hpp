//Tida Sooreechine
//Final Project, 12/5/15

//potions.hpp is the Potions class specification file

#ifndef POTIONS_HPP
#define POTIONS_HPP

#include "space.hpp"
#include "hogwarts.hpp"

using std::cout;

//Potions class declaration
class Potions : public Space
{
private:

public:
	Potions();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
