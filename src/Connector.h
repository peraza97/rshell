#ifndef Connector_h
#define Connector_h
#include "Shell.h"
#include <iostream>

using namespace std;

class Connector : public Shell
{
  protected:
  Shell * left;
  Shell * right;

  public:
  Connector();
  Connector(Shell *l, Shell * r);
  ~Connector();
  virtual bool execute() = 0;

};
#endif
