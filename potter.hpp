//Tida Sooreechine
//Final Project, 12/5/15

//potter.hpp is the Potter class specification file

#ifndef POTTER_HPP
#define POTTER_HPP

#include <iostream>
#include <vector>
#include <string>

#include "die.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

//Potter class declaration
class Potter 
{
private:
	bool alive;
	bool ron;
	bool hermione;
	int wins;
	vector<string> bag;

public:
	Potter();
	void setDead();
	bool getStatus();
	bool getRon();
	void setRon(bool friend1);
	bool getHermione();
	void setHermione(bool friend2);
	void addSock(string sock);
	int getNumSocks();
	int play(int max); 
	int getWins();
	void setWins();
};

#endif
