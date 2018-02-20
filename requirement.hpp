//Tida Sooreechine
//Final Project, 12/5/15

//requirement.hpp is the Requirement class specification file

#ifndef REQUIREMENT_HPP
#define REQUIREMENT_HPP

#include "space.hpp"
#include "hogwarts.hpp"

using std::cout;

//Requirement class declaration
class Requirement : public Space
{
private:

public:
	Requirement();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
