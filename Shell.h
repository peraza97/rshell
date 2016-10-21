#ifndef SHELL_H
#define SHELL_H
#include <iostream>
using namespace std;

class Shell
{
	protected:
	char* input;
	public:

		Shell(): input(NULL) {};
		Shell(char* command): input(command){};
		virtual bool execute() = 0;
};

#endif
