#include <iostream>
using namespace std;
#include <string>
#include <vector>


typedef union IP
{
  unsigned ip;//四字节ip
  struct{
    unsigned part1:8;
    unsigned part2:8;
    unsigned part3:8;
    unsigned part4:8;
  }ip_seg;
}IP;

void GetString(string & str,IP &ip)//从part之中读取1个个字节的整形转换成字符串
{
  str+=to_string(ip.ip_seg.part1);
  str+='.';
  str+=to_string(ip.ip_seg.part2);
  str+='.';
  str+=to_string(ip.ip_seg.part3);
  str+='.';
  str+=to_string(ip.ip_seg.part4);
}

void GetNum(string &str,IP &ip)//将字符串之中的内容填入ip，读取part
{
  string temp[4];
  int sub=0;
  for(int i=0;i<(int)str.size();i++)
  {
    if(str[i]!='.')
      temp[sub]+=str[i];
    else
    {
      sub++;
    }
  }
  ip.ip_seg.part1=stoi(temp[0]);
  ip.ip_seg.part2=stoi(temp[1]);
  ip.ip_seg.part3=stoi(temp[2]);
  ip.ip_seg.part4=stoi(temp[3]);
  
}


int main()
{
  IP ip;
  ip.ip=135133513;
  string str;
  GetString(str,ip);
  cout<<str<<endl;
  cout<<"________________"<<endl;
  IP ip2;
  GetNum(str,ip2);
  cout<<ip2.ip<<endl;


  return 0;
}