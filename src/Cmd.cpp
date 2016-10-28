#ifndef CMD_CPP
#define CMD_CPP
#include "Cmd.h"



bool Cmd::execute()
{
  char * list[1000];
  bool status = true;
  //fork the process
  pid_t pid = fork();

  //the process fails
  if(pid < 0)
  {
    perror("fork failed");
    status = false;
  }

  //the child process
  else if(pid == 0)
  {
    if(execvp(list[0],list) == -1)
    {
      status = false;
      perror("child process");
    }

  }
  //parent process
  else if(pid > 0)
  {
    wait(0);

  }

  return status;
}
#endif
