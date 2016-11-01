#include "Exit.h"
#include "Shell.h"
#include <iostream>
using namespace std;

bool Exit::execute()
{
  cout << "logout" << endl;
exit(0);
}
