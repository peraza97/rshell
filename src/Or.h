#ifndef Or_h
#define Or_h
#include "Connector.h"
#include <iostream>

class Or: public Connector
{
  public:
  Or(): Connector(){};
  Or(Shell * l, Shell * r): Connector(l,r){};
  bool execute();
};
#endif
