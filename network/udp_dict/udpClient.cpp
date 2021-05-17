#include "udpClient.hpp"


void Usage()
{
  cout<<"Usage:"<<"please enter Server ip and port"<<endl;
}

int main(int argc,char *argv[])
{
  if(argc!=3)
  {
    Usage();
    exit(2);
  }

  udpClient *uc =new udpClient(argv[1],atoi(argv[2]));
  uc->initClient();
  uc->start();



  return 0;
}
