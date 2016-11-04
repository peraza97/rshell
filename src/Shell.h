#ifndef Shell_h
#define Shell_h
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

class Shell
{
  public:
  Shell(){};
  virtual ~Shell();
  virtual bool execute() = 0;
};
#endif
