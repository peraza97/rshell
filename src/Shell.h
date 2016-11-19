#ifndef Shell_h
#define Shell_h
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;

class Shell
{
  public:
  Shell(){};
  virtual ~Shell();
  virtual bool execute() = 0;
  int miniParser(char * cmd, char * tok[]);

};
#endif
