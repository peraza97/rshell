 #include "Semi.h"
bool Semi::execute()
{
  left->execute();
  return right->execute();
}
