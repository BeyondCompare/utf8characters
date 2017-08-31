/**
 * @file utf8characters.cpp
 * @brief 
 * @author culbertyang
 * @version 1.0
 * @date 2017-08-31
 */


#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int numberofcharacters(const std::string& utf8str)
{
  int num = 0;
  if(utf8str.empty())
  {
    return num;
  }
  int index = 0;
  int maxlength = utf8str.length();
  while(index < maxlength)
  {
    int curByteLen = 0;
    if((0xF0 & utf8str[index]) == 0xF0)
    {
      curByteLen = 4;
    }
    else if((0xE0 & utf8str[index]) == 0xE0)
    {
      curByteLen = 3;
    }
    else if((0xC0 & utf8str[index]) == 0xC0)
    {
      curByteLen = 2;
    }
    else
    {
      curByteLen = 1;
    }
    if(index + curByteLen <= maxlength)
    {
      index += curByteLen;
    }
    else
    {
      break;
    }
    ++num;
  }
  return num;
}

int main(int argc, char** argv)
{
  std::string testStr = "A中华";
  int num = numberofcharacters(testStr);
  std::cout<<"num = "<<num<<endl;
  return EXIT_SUCCESS;
}
