//Tida Sooreechine
//Final Project, 12/5/15

//gryffindor.hpp is the Gryffindor class specification file

#ifndef GRYFFINDOR_HPP
#define GRYFFINDOR_HPP

#include "space.hpp"
#include "hogwarts.hpp"

using std::cout;

//Gryffindor class declaration
class Gryffindor : public Space
{
private:

public:
	Gryffindor();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
