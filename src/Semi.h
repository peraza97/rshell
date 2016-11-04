#ifndef Semi_h
#define Semi_h
#include "Connector.h"
#include <iostream>

class Semi: public Connector
{
  public:
  Semi(): Connector() {};
  Semi(Shell * l, Shell * r): Connector(l,r){};
  bool execute();
};
#endif
