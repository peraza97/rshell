#ifndef Test_h
#define Test_h
#include "Shell.h"
#include <sys/stat.h>

class Test: public Shell
{
  protected:
  char * command;
  public:
  Test();
  Test(char *);
  ~Test();
  bool execute();
};
#endif
