#ifndef SHELL_H
#define SHELL_H
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>


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
