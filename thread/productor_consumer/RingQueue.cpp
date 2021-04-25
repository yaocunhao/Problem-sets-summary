#include "RingQueue.hpp"

pthread_mutex_t pro_lock;//生产者组内竞争锁
pthread_mutex_t con_lock;//消费者组内竞争锁

int count=0;//生产者数据

void Lock(pthread_mutex_t &lock)
{
  pthread_mutex_lock(&lock);
}

void ULock(pthread_mutex_t &lock)
{
  pthread_mutex_unlock(&lock);
}

  void *Get(void *arg)
{
  RingQueue *q=(RingQueue*)arg;
  while(1)
  {
    usleep(1);
    int data=0;
    Lock(con_lock);//组内竞争
    q->Get(data);//获取数据
    ULock(con_lock);
    std::cout<<pthread_self()<<":consumer get data...:"<<data<<std::endl;
  }
}
void *Put(void *arg)
{
  RingQueue *q=(RingQueue*)arg;
  while(1)
  {
    sleep(1);//增加系统调用
    Lock(pro_lock);//组内竞争
    q->Put((++count)%10);
    ULock(pro_lock);
    std::cout<<pthread_self()<<":productor put data...."<<std::endl;
  }

}

int main()
{
//创建交易场所
  RingQueue *q=new RingQueue(5);

  //初始化锁
  pthread_mutex_init(&con_lock,nullptr);
  pthread_mutex_init(&pro_lock,nullptr);
  
  //创建线程
  pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
  pthread_create(&tid1,nullptr,Put,q);
  pthread_create(&tid2,nullptr,Put,q);
  pthread_create(&tid3,nullptr,Put,q);
  pthread_create(&tid4,nullptr,Get,q);
  pthread_create(&tid5,nullptr,Get,q);
  pthread_create(&tid6,nullptr,Get,q);


//等待线程、避免内存泄漏，不关心返回值
  pthread_join(tid1,nullptr);
  pthread_join(tid2,nullptr);
  pthread_join(tid3,nullptr);
  pthread_join(tid4,nullptr);
  pthread_join(tid5,nullptr);
  pthread_join(tid6,nullptr);

  //销毁工作
  pthread_mutex_destroy(&con_lock);
  pthread_mutex_destroy(&pro_lock);
  delete q;




  return 0;
}
