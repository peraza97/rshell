#include "Or.h"

bool Or:: execute()
{
  bool status = true;
  if(!left->execute())
  {
    if(!right->execute())
    {
      status = false;
    }
  }
  
  return status;

}
