#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <iostream>
#include "Shell.h"
using namespace std;

class Connector : public Shell
{
	protected:
	Shell* left;
	Shell* right;

	public:
	Connector(){};
	Connector(Shell * l, Shell * r):left(l), right(r){};
	bool execute();
};

#endif
