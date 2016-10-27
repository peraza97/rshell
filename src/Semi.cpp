#include "Semi.h"

bool Semi::execute()
{
	left->execute();
	right->execute();
	return true;
}
