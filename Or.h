#ifndef OR_H
#define OR_H
#include "Connector.h"

class Or : public Connector
{
  public:
    Or(){};
    Or(Shell * l, Shell * r): Connector(l,r){};
    bool execute();

};

#endif
