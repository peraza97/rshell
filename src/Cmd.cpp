 #include "Cmd.h"

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
 delete[] command;
 command = NULL;
}
bool Cmd::execute()
{
  bool status = true;

  char * list[500];
  Shell::miniParser(command,list);

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
