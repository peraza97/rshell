#include "Shell.h"
#ifndef CMD_H
#define CMD_H
#include <iostream>
using namespace std;

class cmd : public Shell
{
	public:
	bool execute();	
}
	
#endif
