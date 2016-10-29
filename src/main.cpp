#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

#include "Shell.h"
#include "Cmd.h"
#include "Exit.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semi.h"

using namespace std;


void info()
{
  //retrieve username
  register struct passwd *p;
  register uid_t uid;
  uid = geteuid ();
  p = getpwuid (uid);
  if (p)
    {
      cout << p->pw_name;
    }

  //retrieve host name
  char host[500];
  host[499] = '\0';
  gethostname(host, 499);
  printf("@%s", host);

}


int main(int argc, char *argv[])
{
  //variables
  string input;


  //infinite loop
  for(;;)
  {
  //output the username and the host machine
  info();
  cout << "$ ";

  //retrieve the input from the user
  getline(cin, input);
  
  char * p = new char[input.size() - 1];
  //the input is now in a char array
  strcpy(p,input.c_str());

  /*
  Shell * cmd = new Cmd(p);
  cmd->execute();
  */

  }


return 0;
}
