#include "Exit.h"
#include <stdlib.h>

bool Exit::execute()
{
  cout << "logout"<< endl;
  exit(0);
}
