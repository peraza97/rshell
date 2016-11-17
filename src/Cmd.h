#ifndef Cmd_h
#define Cmd_h
#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Shell.h"
#include <iostream>
using namespace std;

class Cmd: public Shell
{
  protected:
  char * command;

  public:
  Cmd();
  Cmd(string );
  ~Cmd();

  bool execute();

};
#endif
