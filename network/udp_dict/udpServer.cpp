#include "udpServer.hpp"

void Usage()
{
  cout<<"Usage:"<<"please enter server ip and port"<<endl;
}

int main(int argc,char*argv[])
{
  if(argc!=2)
  {
    Usage();
    exit(1);
  }

  udpServer *up=new udpServer(atoi(argv[1]));
  up->initServer();//初始化
  up->start();//运行起来

  return 0;
}
