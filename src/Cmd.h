#ifndef CMD_H
#define CMD_H
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>
#include "Shell.h"

using namespace std;

class Cmd : public Shell
{
	private:
	char * cmd;
	public:
	Cmd(): cmd(NULL) {};
	Cmd(char* userInput): cmd(userInput) {};
	~Cmd();
	bool execute();
};

#endif
