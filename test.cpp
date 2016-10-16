#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

//global variable
char * argv[10];

void parse(char  command[] , char * argv[])
{
  char * tok = strtok(command, " ||");
  while(tok != NULL)
  {
    cout << tok << endl;
    tok = strtok(NULL," ||");

  }

}


int main()
{
//the command user enters
char command[100];
//lavel my process
pid_t pid;

//simple while loop to keep the terminal running if q is not entered
while(strcmp(command,"q"))
{
  printf("%s","$");
  cin.getline(command, 100);
  parse(command, argv);
}
return 0;

}
