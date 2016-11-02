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
	Connector(): left(NULL), right(NULL) {};
	Connector(Shell * l, Shell * r):left(l), right(r){};
	~Connector()
	{
		delete left;
		delete right;
	}
	virtual bool execute() = 0;
};

#endif
