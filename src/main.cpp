#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

#include "Shell.h"
#include "Cmd.cpp"
#include "Exit.cpp"
#include "Connector.cpp"
#include "And.cpp"
#include "Or.cpp"
#include "Semi.cpp"

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
  info();
  cout << "$ ";
  getline(cin, input);
  char * p = new char[input.size() - 1];
  strcpy(p,input.c_str());

  Shell * cmd = new Cmd(p);
  cmd->execute();

  }


return 0;
}
