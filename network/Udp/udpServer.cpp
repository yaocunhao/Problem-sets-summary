#include "udpServer.hpp"


int main()
{
  udpServer *up=new udpServer();
  up->initServer();//初始化
  up->start();//运行起来

  return 0;
}
