#ifndef AND_H
#define AND_H
#include "Connector.h"

class And : public Connector
{
	public:
	And(){};
	And( char* userInput): Connector(userInput){};
	bool execute();

};

#endif
