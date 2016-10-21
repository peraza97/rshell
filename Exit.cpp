#include "Exit.h"
#include "Shell.h"
#include <iostream>
using namespace std;

bool Exit:: execute()
{
	cout << input[0];
	return true; 
}
