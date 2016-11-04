#ifndef Cmd_h
#define Cmd_h
#include "Shell.h"
#include <iostream>
using namespace std;

class Cmd: public Shell
{
  protected:
  char * command;

  public:
  Cmd();
  Cmd(char *);
  ~Cmd();

  bool execute();

};
#endif
