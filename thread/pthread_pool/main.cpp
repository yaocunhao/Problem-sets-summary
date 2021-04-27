#include "pool.hpp"

int main()
{
  Pool *p=new Pool;//创建一个线程池
  p->Init();
  
  //构造任务
  int count=0;
  while(1)
  {
    srand((unsigned)time(NULL));
    int val=rand()%5;
    Test t(val);
    p->Put(t);
   // cout<<val<<endl;
   sleep(1);
  }

  return 0;
}
