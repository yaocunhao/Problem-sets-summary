#include "client.hpp"

void Usage(string str)
{
  cout<<"Usage"<<"\t"<<"\n";
  cout<<str<<":"<<"please enter your ip and port"<<endl;
}

int main(int argc , char *argv[])
{
  if(argc!=3)
  {
    Usage(argv[0]);
    exit(5);
  }

 Client *ct = new Client(argv[1],atoi(argv[2]));
 ct->InitClient();
 ct->start();

  delete ct;

  return 0;
}
