#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

void parseLine(char * cmd)
{

char * tok[1000];
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
  execvp(tok[0],tok);

}

int main(int argc, char *argv[])
{

  //the loop that keeps the shell going for ever
  for(;;)
  {
    string usr;
    //first thing to do is print out the $ before everyline
    cout << "$";
    // Get input from the user and then turn it into a char   * array
    getline(cin,usr);
    char *cmd = new char[usr.size() + 1];
    strcpy(cmd, usr.c_str());
    parseLine(cmd);
  }

return 0;
}
