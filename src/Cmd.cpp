#include "Cmd.h"

void parseData(char * cmd, char * tok [])
{

//char * tok[1000];
//char array for tokenizing
char *part = strtok(cmd, " ");
int i = 0;
tok[i] = part;
  while(part != NULL)
  {
    part = strtok(NULL, " ");
    tok[++i] = part;
  }
  //tok[i]= NULL;
}

bool Cmd::execute()
{
  char * list[1000];
  bool status = true;

  parseData(cmd,list);
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
      perror("execution error");
      exit(1);
    }

  }
  //parent process
  else if(pid > 0)
  {
    int st;
    if(waitpid(pid, &st,0) == -1)
    {
      perror("wait failure");
    }

  }

  return status;
}
