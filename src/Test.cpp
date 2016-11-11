#include "Test.h"
Test::Test()
{
    command = NULL;
}

Test::Test(char * cmd)
{
    command = cmd;
}

bool Test::execute()
{
    //variables needed
    struct stat buf;
    char * list[1000];
    string flag;
    string path;
    int temp = Shell::miniParser(command,list);
    //if there is only one element, the path
    if(temp == 1)
    {
      flag = "-e";
      path = string(list[0]);
    }
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
      perror(path.c_str());
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
