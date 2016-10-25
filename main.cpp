#include <pwd.h>
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


//this removes the input after a # symbol
void removeComment(string &line)
{
  size_t comment = line.find("#");
  if(comment!= string::npos)
  {
    line= line.substr(0,comment);
  }

}

void hostName()
{

  register struct passwd *p;
  register uid_t uid;
  uid = geteuid ();
  p = getpwuid (uid);
  if (p)
    {
      cout << p->pw_name;
    }

char host[500];
host[499] = '\0';
gethostname(host, 499);
printf("@%s", host);

}


int main(int argc, char *argv[])
{
  int a;
  //the loop that keeps the shell going for ever
  cin >> a;
  while(a != 0)
  {
      hostName();
      cout << "$ ";
      cin >> a;
  }

return 0;
}
