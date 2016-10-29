#ifndef AND_CPP
#define AND_CPP
#include "And.h"

bool And::execute()
{

	if(left->execute())
	{
		return right->execute();
	}
	return false;
}
#endif
