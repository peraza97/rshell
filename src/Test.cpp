#include "Test.h"
Test::Test()
{
    command = NULL;
}

Test::Test(string cmd)
{
  char * t = new char[cmd.size() - 1];
  strcpy(t,cmd.c_str());
  this->command = t;
}

Test::~Test()
{

    delete[] command;
    command = NULL;
}

bool Test::execute()
{
  if(command == NULL)
  {
    cout << "(False)" << endl;
    return false;
  }
    //variables needed
    struct stat buf;
    char * list[500];
    string flag;
    string path;
    int temp = Shell::miniParser(command,list);
    //if there is only one element
    //this means that there was no flag
    if(temp == 1)
    {
      flag = "-e";
      path = string(list[0]);
    }
    //there is a flag
    else
    {
      flag = string(list[0]);
      path = string(list[1]);
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
