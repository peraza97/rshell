#ifndef Exit_h
#define Exit_h
#include "Shell.h"
#include <iostream>
using namespace std;
class Exit: public Shell
{
  public:
  Exit(){};
  bool execute();

};
#endif
