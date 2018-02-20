//Tida Sooreechine
//Final Project, 12/5/15

//dada.hpp is the Dada class specification file

#ifndef DADA_HPP
#define DADA_HPP

#include "space.hpp"

using std::cout;

//Dada class declaration
class Dada : public Space
{
private:

public:
	Dada();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
