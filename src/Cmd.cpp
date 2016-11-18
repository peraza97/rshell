 #include "Cmd.h"

Cmd::Cmd()
{
  command = NULL;
}

Cmd::Cmd(string cmd)
{
char * t = new char[cmd.size() - 1];
strcpy(t,cmd.c_str());
this->command = t;
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
  int size = Shell::miniParser(command,list);

//this segment of the code is for the cd command
  register struct passwd *p;
  register uid_t uid;
  uid = getuid ();
  string name = "/home/";
  p = getpwuid (uid);

  if(p)
  {
  name +=p->pw_name;
  }

  if(string(list[0]) == "cd")
  {
    //if there is a path to change
    if(size > 1)
    {
      string arg = string(list[1]);
      //check if there is a tilda
      if(arg.find("~") != string::npos)
      {
        arg.replace(arg.find("~"),1,name);
      }
      //check if it passes
      if(chdir(arg.c_str()) == -1)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    //no path specified so return true
    else
    {
      return true;
    }
  }

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
