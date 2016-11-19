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
#include <queue>
#include <stack>
using namespace std;

class Cmd: public Shell
{
  protected:
  char * command;
  queue<char *> arg;

  public:
  Cmd();
  Cmd(string);
  ~Cmd();

  bool execute();

};
#endif
