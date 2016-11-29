#include "Cd.h"
bool Cd::execute()
{
  //no path specified
  if(arg.size() == 0)
  {
    char * home = getenv("HOME");
    char * old = getenv("PWD");
    //error checking
    if(home == NULL || old == NULL)
    {
      perror("getenv");
    }

    //if chdir fails
    if(chdir(home) == -1)
    {
      return false;
    }
    //succeeds so we need set env variables
    else
    {
     if(setenv("PWD",home, 1) == -1)
      {
        perror("setenv PWD");
      }
      if(setenv("OLDPWD",old, 1) == -1)
      {
        perror("setenv OLDPWD");
      }
      return true;
     }
   }

  //path specified
  else
  {
    char * path = arg.front();
    char * old = getenv("PWD");
    if(old == NULL)
    {
      perror("getenv");
    }
    if(path == NULL)
    {
      return false;
    }
    //if -, then get OLDPWD
    if(string(path) == "-")
    {
      path = getenv("OLDPWD");
    }

    //change the directory
    if(chdir(path) == -1)
    {
      return false;
    }
    //have to set the environment variable
    else
    {
      char p[1024];
      getcwd(p,1024);
      //error checking
      if(setenv("PWD",p, 1) == -1)
      {
        perror("setenv");
      }
      if(setenv("OLDPWD",old, 1) == -1)
      {
        perror("setenv OLDPWD");
      }
    
      return true;
    }
  }
  return true;
}
