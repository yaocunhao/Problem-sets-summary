#include "tcpServer.hpp"

void Usage()
{
  cout<<"please enter your port"<<endl;
}
int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    Usage();
    exit(1);
  }
      tcpServer *tp=new tcpServer(stoi(argv[1]));//传输的是字符串 -> int
      tp->initServer();
      tp->stat();

    delete tp;
    return 0;
  }
  




