#ifndef Test_h
#define Test_h
#include "Shell.h"
#include <queue>
#include <sys/stat.h>

class Test: public Shell
{
  protected:
  char * command;
  public:
  Test();
  Test(string );
  ~Test();
  bool execute();
};
#endif
