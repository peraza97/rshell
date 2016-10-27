#ifndef EXIT_H
#define EXIT_H
#include <iostream>
#include "Shell.h"
using namespace std;

class Exit : public Shell
{
	public:
	Exit(){};
	Exit(char * userInput): Shell(userInput){};
	bool execute();
};

#endif
