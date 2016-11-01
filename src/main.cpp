#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>
#include<queue>
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
  cout << "$ ";
}

void print_vec(vector<string> v)
{
  for(unsigned i = 0; i < v.size(); ++i)
  {
    cout << " |" << v.at(i) << "| ";
  }
}


int priority(string op)
{
  int priority = 0;
  if(op == "(")
  {
    priority =  3;
  }
  else if(op == "&&" || op == "||")
  {
      priority = 2;
  }
  else if(op == ";")
  {
      priority = 1;
  }
  return priority;
}

vector<string> infix_to_postfix(vector<string> v)
{
  stack<string> s;
  vector<string> result;
  string c;
  for(unsigned i = 0; i< v.size();++i)
  {
       c = v.at(i);
       //c is a Connector
       if(c == "||" || c == "&&" || c == ";" || c == "(" || c == ")")
       {
           if( c == "(")
           {
               s.push(c);
           }
           else if(c == ")")
           {
                while(s.top() != "(")
                {
                    result.push_back(s.top());
                    s.pop();
                }
                s.pop();
           }
           else
           {
                    while(!s.empty() && priority(c) <= priority(s.top()))
                    {
                        if(s.top() == "(")
                        {
                            break;
                        }
                        result.push_back(s.top());
                        s.pop();
                    }
                  s.push(c);
            }
          }
        //its a command
        else
        {
          result.push_back(c);
        }
    }



    while(!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
  return result;

}

void SubStrBuilder(vector<string> &cmdVector,string a)
{
  //This function parses up the user input into substrings of cmds, exits and connectors
  //It also handles how to build the substrings in case of quotation marks and # comments
	string::iterator it = a.begin();
	string newStr;
  bool quote = false;                     //used to keep track if the current input is part of a quote

	while (it != a.end())                   //iterates through the string
  {
    if(quote)                     //if currently in quote
    {
      if(*it != '\"')             //checks if quote ends
      {
        newStr += *it;
      }
      else
      {
        quote = false;
      }
        it++;
    }
    else
    {
      if(*it == '(' || *it == ')' || *it == ';')                      //Semi colon and parenthesis connector check
      {
        if(newStr != "" )
        {
          cmdVector.push_back(newStr);
        }

        char def = *it;
        string b = "";
        b+=def;
        cmdVector.push_back(b);
        if((it+1) != a.end())
        {
          it+=1;
        }
        else
        {
          it = a.end();
        }
        newStr = "";
      }

      else if(*it == ' ' && newStr == "") //Ignore empty strings and whitespaces
      {
        it++;
        continue;
      }
      else if(*it == '|')                 //Or connector check
      {
        if(*(it+1) == '|')
        {
          if(newStr != "" )
          {
            cmdVector.push_back(newStr);
          }
          string temp = "||";
          cmdVector.push_back(temp);
          if(it+2 != a.end())
          {
            it += 2;
          }
          else
          {
            it = a.end();
          }
          newStr = "";
        }
        else{it++;}
      }
      else if(*it == '&')                 //And Connector check
      {
        if(*(it+1) == '&')
        {
          if(newStr != "" )
          {
            cmdVector.push_back(newStr);
          }
          string temp = "&&";
          cmdVector.push_back(temp);
          if(it+2 != a.end())
          {
            it += 2;
          }
          else
          {
            it = a.end();
          }
          newStr = "";
        }
        //newStr += *it;
        else{it++;}
      }
      else if(*it == '#')                 //checks if there is a comment in the input. If so, the rest of the input is ignored
      {
          it = a.end();


      }
      else
      {
        if(*it == '\"')                   //checks for starting quotation
        {
          quote = true;
        }
        else
        {
          newStr += *it;
        }
        it++;
      }
    }
  }
  if(newStr != "")                        //this stops any empty strings from being added/categorized
  {
    cmdVector.push_back(newStr);
  }
}

Shell * createNodes(string s)
{
  Shell * temp;
  char * p = new char[s.size() - 1];
  //the input is now in a char array
  strcpy(p,s.c_str());

  if(s == "exit")
  {
   temp = new Exit();
  }
  else
  {
    temp = new Cmd(p);
  }

  return temp;

}

Shell * compose_tree(vector<string> v)
{
  //this stack will create our tree
  stack<Shell *> shell;
  unsigned index = 0;
  while(index < v.size() )
  {
    if(v.at(index) == "||")
    {
      if(shell.size()>1)
      {
        Shell * r = shell.top();
        shell.pop();
        Shell * l = shell.top();
        shell.pop();
        Shell * temp = new Or(l,r);
        shell.push(temp);
      }
    }
    else if( v.at(index) == "&&")
    {
      if(shell.size()>1)
      {
        Shell * r = shell.top();
        shell.pop();
        Shell * l = shell.top();
        shell.pop();
        Shell * temp = new And(l,r);
        shell.push(temp);
      }
    }
    else if( v.at(index) == ";")
    {
      if(shell.size()>1)
      {
        Shell * r = shell.top();
        shell.pop();
        Shell * l = shell.top();
        shell.pop();
        Shell * temp = new Semi(l,r);
        shell.push(temp);
      }
    }
    else
    {
      Shell * temp = createNodes(v.at(index));
      shell.push(temp);
    }
    index++;
  }
  if(shell.size())
  {
  return shell.top();
  }
  else
  {
    return NULL;
  }
}


int main(int argc, char *argv[])
{
  //variables
  string input ="";
  vector<string> comVector;
  Shell * master = NULL;
  //infinite loop
  do
  {
    //output the username and the host machine
    info();
    //this seperates the command into a vector
    SubStrBuilder(comVector,input);
    //turns the vector into postfix notation
    comVector = infix_to_postfix(comVector);

    //if the vector has elements in it this means at least 1 command entered
    if(!comVector.empty())
    {
        //return the top node
        master =  compose_tree(comVector);
        //if there is a valid Shell * to execute
        if(master != NULL)
        {
          master->execute();
        }
        //if there wasnt that means there wasnt a valid command entered
    }

      //clear the variables for the next iteration
   comVector.clear();
   input = "";


 }while(getline(cin, input));

  return 0;
}
