#include "Shell.h"
#include <cstring>
#include <string>

char** Shell::parse()
{
	char** tok = new char* [1000];
	//char array for tokenizing
	char *part = strtok(cmd, " ");
	int i = 0;
	tok[i] = part;
	while(part != NULL)
	{
		part = strtok(NULL, " ");
		tok[++i] = part;
	}
	tok[i]= NULL;
	return tok;
}
