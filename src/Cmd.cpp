 #include "Cmd.h"

Cmd::Cmd()
{
  command = NULL;
}

Cmd::Cmd(string cmd)
{
  this->command = NULL;
  string temp = "";
  char spot;
  for(unsigned i = 0; i < cmd.size(); ++i)
  {
    spot = cmd.at(i);
    //if spot is a space
    if(spot == ' ')
    {
      if(temp!= "")
      {
        char * a = new char [temp.size()-1];
        memcpy(a, temp.c_str(), temp.size() + 1);
        if(command == NULL)
        {
          command = a;
        }
        else
        {
          arg.push(a);
        }
      }

      temp = "";
    }
    //if space is a letter
    else
    {
    temp+=spot;
    }
  }
  //if the foor loop ends but the temp string
  //has not been cleared
  //if temp is not empty at the end
  if(temp != "")
  {
    char * a = new char [temp.size()-1];
    memcpy(a, temp.c_str(), temp.size() + 1);
    if(command == NULL)
    {
      command = a;
    }
    else
    {
      arg.push(a);
    }
  }

}

Cmd::~Cmd()
{
  delete[] command;
  while(arg.size() > 0)
  {
     char * a = arg.front();
     arg.pop();
     delete[] a;
  }
}


bool Cmd::execute()
{
    bool status = true;
    char * list[500];
    int i = 1;
    int arg_size = arg.size();
    queue<char * > arg_2;

    //set list[0] to the command
    list[0] = command;
    //set the rest to the flags
    while(arg.size() > 0)
    {
      char * a = arg.front();
      arg.pop();
      list[i] = a;
      arg_2.push(a);
      ++i;
    }
    list[i] = NULL;

    while(arg_2.size() > 0)
    {
      char * a = arg_2.front();
      arg_2.pop();
      arg.push(a);
    }

//this segment of the code is for the cd command
  if(string(command) == "cd")
  {
    char * home = getenv("HOME");
    if(home == NULL)
    {
      perror("getenv");
    }
    //no path specified
    if(arg.size() == 0)
    {

      if(chdir(home) == -1)
      {
        return false;
      }
      else
      {
        if(setenv("PWD",home, 1) == -1)
        {
          perror("setenv");
          return false;
        }
        return true;
      }
    }
    //path specified
    else
    {
      string path = string(arg.front());
      if(path.find('-') != string::npos)
      {
        path.replace(path.find("-"),1,"..");
      }
      if(chdir(path.c_str()) == -1)
      {
        return false;
      }
      else
      {
        char * p = new char[1024];
        getcwd(p,1024);
        if(p == NULL)
        {
        perror("getcwd");
        }
        if(setenv("PWD",p, 1) == -1)
        {
          perror("setenv");
          delete[] p;
          return false;
        }
        delete[] p;
        return true;
      }
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
  for(int j = 0; j <= arg_size; ++j)
  {
    list[j] = NULL;
  }
  return status;
  }
