#include "Shell.h"
#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <iostream>
using namespace std;

class Connector : public Shell
{
	private:
	Shell* left;
	Shell* right;
	public:
	bool execute();	
}
	
#endif
