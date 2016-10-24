#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

#include "Shell.h"
#include "And.h"
#include "Cmd.h"
#include "Connector.h"
#include "Exit.h"
#include "Or.h"
#include "Semi.h"

using namespace std;

void parseLine(char * cmd, char * tok [])
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
  tok[i]= NULL;
}

int main(int argc, char *argv[])
{

  //the loop that keeps the shell going for ever
  for(;;)
  {
    char * tok[1000];
    string usr;
    cout << "$";
    // Get input from the user
    getline(cin,usr);

    /*going to check for any comments now
      and if found, trunkate the string */
    size_t comment = usr.find("#");
    if(comment!= string::npos)
    {
      usr = usr.substr(0,comment);
    }





    char *cmd = new char[usr.size() + 1];
    strcpy(cmd, usr.c_str());
    //fill the tok function with the requred stuffs
    parseLine(cmd,tok);

    pid_t pid = fork();


    if(pid == 0)
    {
    execvp(tok[0],tok);
    }
    else
    {
      wait(0);
    }

  }

return 0;
}
