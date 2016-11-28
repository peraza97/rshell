#include "Test.h"
Test::Test()
{
}

Test::Test(string cmd)
{
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
        arg.push(a);
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
  if(temp != "")
  {
    char * a = new char [temp.size()-1];
    memcpy(a, temp.c_str(), temp.size() + 1);
    arg.push(a);
  }

}

Test::~Test()
{
    while(arg.size() > 0)
    {
       char * a = arg.front();
       arg.pop();
       delete[] a;
    }
}

bool Test::execute()
{
  if(arg.size() == 0)
  {
    cout << "(False)" << endl;
    return false;
  }
    //variables needed
    struct stat buf;
    string flag;
    string path;
    queue<char * > arg_2;
    //if there is only one element
    //this means that there was no flag
    if(arg.size() == 1)
    {
      flag = "-e";
      path = string(arg.front());
    }
    //there is a flag
    else if(arg.size() == 2)
    {
      flag = string(arg.front());
      arg_2.push(arg.front());
      arg.pop();
      path = string(arg.front());
      arg_2.push(arg.front());
      arg.pop();
    }
    while(arg_2.size() > 0)
    {
      char * a = arg_2.front();
      arg_2.pop();
      arg.push(a);
    }

    //now check the path
    int valid = stat(path.c_str(),&buf);

    //path does not exist
    if(valid == -1)
    {
      cout << "(False)" << endl;
      return false;
    }
    //check if it path exists
    if(flag == "-e")
    {
      cout <<"(True)"<<endl;
      return true;
    }
    //check if its a regular file
    else if(flag == "-f")
    {
      if(S_ISREG(buf.st_mode))
      {
        cout<<"(True)"<<endl;
        return true;
      }
      else
      {
        cout<<"(False)"<<endl;
        return false;
      }
    }
    //if it is a directory
    else if(flag == "-d")
    {
      if(S_ISDIR(buf.st_mode))
      {
        cout<<"(True)"<<endl;
        return true;
      }
      else
      {
        cout<<"(False)"<<endl;
        return false;
      }
    }
    //if all fails, just return false
    return false;
}
