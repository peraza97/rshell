#include "exit.h"
#include <iostream>
using namespace std;

exit::exit(char* userInput[])
{
	input = userInput;
}

bool exit::execute()
{
	if (execvp(userInput[], userInput) == -1);
	{
		return false;
	}
	return true;	
}
	
		
