 #include "Cmd.h"

void miniParser(char * cmd, char * tok[])
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

}

Cmd::Cmd()
{
  command = NULL;
}

Cmd::Cmd(char * cmd)
{
  this->command = cmd;
}

Cmd::~Cmd()
{
  delete command;
}
bool Cmd::execute()
{
  bool status = true;

  char * list[1000];
  miniParser(command,list);

  //list now has the command in array form
  //fork the process
  pid_t pid = fork();
  //child process
  if(pid == 0)
  {
    int result = execvp(list[0],list);
    if(result == -1)
    {
      string error = "rshell: ";
      error += (string)list[0];
      perror(error.c_str());
      _exit(1);
    }
  }
  //parent process
  else if(pid > 0)
  {
    int child;
    if(waitpid(pid,&child,0) == -1)
    {
      perror("wait failure");
    }
    if(WEXITSTATUS(child))
    {
      status = false;
    }
  }

  return status;

}
