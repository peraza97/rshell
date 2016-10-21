#ifndef SEMI_H
#define SEMI_H
#include "Connector.h"

class Semi : public Connector
{
  public:
  Semi(){};
  Semi(char* userInput): Connector(userInput){};
  bool execute();

};

#endif
