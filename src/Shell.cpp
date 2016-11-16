 #include "Shell.h"

Shell::~Shell()
{
}

int Shell::miniParser(char * cmd, char * tok[])
{
  //cmd is the protected member
  //tok is the array that will be taken in
  char * part = strtok(cmd," ");
  int i = 0;
  while(part!=NULL)
  {
    tok[i] = part;
    part = strtok(NULL, " ");
    ++i;
  }
  tok[i] = NULL;
  return i;
}
