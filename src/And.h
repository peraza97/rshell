#ifndef AND_H
#define AND_H
#include "Connector.h"

class And : public Connector
{
	public:
	And(): Connector() {};
	And(Shell * l, Shell * r): Connector(l,r){};
	bool execute();

};

#endif
