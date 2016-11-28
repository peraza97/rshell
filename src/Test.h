#ifndef Test_h
#define Test_h
#include "Shell.h"
#include <queue>
#include <sys/stat.h>
#include <iostream>
#include <queue>
#include <stack>

class Test: public Shell
{
  protected:
  queue<char * > arg;
  public:
  Test();
  Test(string );
  ~Test();
  bool execute();
};
#endif
