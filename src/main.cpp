#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cstring>
#include <stack>
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

}



int priority(string op)
  {
      int priority = 0;
      if(op == "("){
        priority =  3;
      }
      else if(op == "&&" || op == "||"){
          priority = 2;
      }
      else if(op == ";"){
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
	string::iterator it = a.begin();
	string newStr;
  bool quote = false;

	while (it != a.end())
  {
    if(quote)
    {
      if(*it == '\"')
      {
        quote = false;
      }
      newStr += *it;
      it++;
    }
    else
    {
      if(*it == ';')
      {
        if(newStr != "" )
        {
          cmdVector.push_back(newStr);
        }
        cmdVector.push_back(";");
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
      else if(*it == ' ' && newStr == "")
      {
        it++;
        continue;

      }
      else if(*it == '|')
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
      else if(*it == '&')
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
      else if(*it == '#')
      {
        cmdVector.push_back(newStr);
        it = a.end();
        it += 234;
      }
      else
      {
        if(*it == '\"')
        {
          quote = true;
        }
        newStr += *it;
        it++;
      }
    }
  }
  if(newStr != "")
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

  if(s == "||")
  {
    temp = new Or();
  }
  else if(s == "&&")
  {
    temp = new And();
  }
  else if(s == ";")
  {
    temp = new Semi();
  }
  else
  {
    temp = new Cmd(p);
  }

  return temp;

}

Shell * post_fix_tree(vector<string> v)
{
stack<Shell *> shell;
unsigned index = 0;
while(index < v.size() )
  {
    if(v.at(index) == "||")
    {
      Shell * r = shell.top();
      shell.pop();
      Shell * l = shell.top();
      shell.pop();
      Shell * temp = new Or(l,r);
      shell.push(temp);
    }
    else if( v.at(index) == "&&")
    {
      Shell * r = shell.top();
      shell.pop();
      Shell * l = shell.top();
      shell.pop();
      Shell * temp = new And(l,r);
      shell.push(temp);
    }
    else if( v.at(index) == ";")
    {
      Shell * r = shell.top();
      shell.pop();
      Shell * l = shell.top();
      shell.pop();
      Shell * temp = new Semi(l,r);
      shell.push(temp);
    }
    else
    {
      Shell * temp = createNodes(v.at(index));
      shell.push(temp);
    }

    index++;

  }

  return shell.top();
}




int main(int argc, char *argv[])
{
  //variables
  string input;
  vector<string> comVector;

  //infinite loop
  for(;;)
  {
  comVector.clear();
  //output the username and the host machine
  info();
  cout << "$ ";


  //retrieve the input from the user
  getline(cin, input);

  if(!input.size())
  {
    continue;
  }
  SubStrBuilder(comVector,input);

  comVector = infix_to_postfix(comVector);

  Shell * master =   post_fix_tree(comVector);

  master->execute();

  }


return 0;
}
