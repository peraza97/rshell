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
