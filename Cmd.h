#ifndef CMD_H
#define CMD_H
#include <iostream>
#include "Shell.h"
using namespace std;

class Cmd : public Shell
{
	public:
	bool execute();
};

#endif
