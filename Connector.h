#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <iostream>
#include "Shell.h"
using namespace std;

class Connector : public Shell
{
	private:
	Shell* left;
	Shell* right;

	public:
	Connector(){};
	Connector(char * userInput):Shell(userInput){};
	bool execute();
};

#endif
