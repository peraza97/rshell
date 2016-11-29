#ifndef Cd_h
#define Cd_h
#include "Cmd.h"
class Cd : public Cmd
{
  public:
  Cd(string s): Cmd(s){};
  bool execute();

};
#endif
