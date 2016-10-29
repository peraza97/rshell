#ifndef AND_H
#define AND_H
#include "Connector.h"

class And : public Connector
{
	public:
	And(){};
	And(Shell * l, Shell * r): Connector(l,r){};
	bool execute();

};

#endif
