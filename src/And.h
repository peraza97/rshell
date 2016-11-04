#ifndef And_h
#define And_h
#include "Connector.h"
#include <iostream>
using namespace std;

class And: public Connector
{
  public:
  And(): Connector() {};
  And(Shell * l, Shell * r) :Connector(l,r){};
  bool execute();
};
#endif
