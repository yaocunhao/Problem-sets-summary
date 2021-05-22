#include "server.hpp"

void Usage(string str)
{
  cout<<"Usage"<<"\t"<<"\n";
  cout<<str<<":"<<"please enter your port"<<endl;
}

int main(int argc , char *argv[])
{
  if(argc!=2)
  {
    Usage(argv[0]);
    exit(5);
  }

  Server *sv=new Server(stoi(argv[1]));
  sv->InitServer();
  sv->start();
 


  delete sv;

  return 0;
}
