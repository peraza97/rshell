#ifndef SEMI_H
#define SEMI_H
#include "Connector.h"

class Semi : public Connector
{
  public:
  Semi(): Connector() {};
  Semi(Shell * l, Shell * r): Connector(l,r){};
  bool execute();

};

#endif
