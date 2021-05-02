#include"h2o.hpp"
#include <unistd.h>

int main()
{
  H2O h;
  h.Init();

  int count=0;
while(1)
{
  usleep(100000);
  char data;
  h.Take(data);
  cout<<data;
  fflush(stdout);
  count++;
  if(count%3==0)
    cout<<endl;
}

  return 0;
}

