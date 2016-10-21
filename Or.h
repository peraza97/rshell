#ifndef OR_H
#define OR_H
#include "Connector.h"

class Or : public Connector
{
  public:
    Or(){};
    Or(char* userInput);
    bool execute();

};

#endif
