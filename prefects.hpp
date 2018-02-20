//Tida Sooreechine
//Final Project, 12/5/15

//prefects.hpp is the Prefects class specification file

#ifndef PREFECTS_HPP
#define PREFECTS_HPP

#include "space.hpp"
#include "hogwarts.hpp"

using std::cout;

//Prefects class declaration
class Prefects : public Space
{
private:

public:
	Prefects();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
