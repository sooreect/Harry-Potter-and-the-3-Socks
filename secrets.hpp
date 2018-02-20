//Tida Sooreechine
//Final Project, 12/5/15

//secrets.hpp is the Secrets class specification file

#ifndef SECRETS_HPP
#define SECRETS_HPP

#include "space.hpp"
#include "hogwarts.hpp"

using std::cout;

//Secrets class declaration
class Secrets : public Space
{
private:

public:
	Secrets();
	virtual void getTask();
	virtual bool special(int number);
};

#endif
