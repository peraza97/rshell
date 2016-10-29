#ifndef SEMI_CPP
#define SEMI_CPP
#include "Semi.h"

bool Semi::execute()
{
	left->execute();
	if(right->execute())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif
