#pragma once
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <queue>
#include <unistd.h>
using namespace std;
#define NUM 5

class Test
{
  private:
    int _val;
  
  public:
    Test()
    {}

    Test(int val)
      :_val(val)
    {}

    void Run()
    {
      cout<<"thread["<<pthread_self()<<"]"<<"run test...:"<<pow(_val,2)<<endl;
    }
};


class Pool
{
  private:
    int _max;//线程个数
    queue<Test*> q;//存指针，减少数据拷贝消耗
    pthread_mutex_t lock;
    pthread_cond_t cond;

  public:
    
    Pool(int max=NUM)
      :_max(max)
    {}

    void TestLock()
    {
      pthread_mutex_lock(&lock);
    }

    void TestUnlock()
    {
      pthread_mutex_unlock(&lock);
     }

    void ThreadWait()
    {
      pthread_cond_wait(&cond,&lock);
    }

    void ThreadWakeUp()
    {
      //pthread_cond_signal(&cond);//一次唤醒一个
      pthread_cond_broadcast(&cond);//全部唤醒
    }

    bool IsEmpty()
    {
      return q.size()==0;
    }

    void Put(Test &data)//外部放入数据
    {
      TestLock();
      q.push(&data);
      TestUnlock();
      ThreadWakeUp();//唤醒一个线程
    }

    void Get(Test &data)//内部线程池完成任务
    {
      Test *t=q.front();
      q.pop();
      data=*t;
    }

public:
    //必须设置为静态的，因为成员函数会有this形参
    static void *RunTest(void *arg)//处理任务函数
    {
      Pool* p_this=(Pool*)arg;
      while(1)
      {
        pthread_detach(pthread_self());
         p_this->TestLock();
         while(p_this->IsEmpty())//没有任务则挂起
         {
           p_this->ThreadWait();
         }
         //将任务拿出来
         Test t;
         p_this->Get(t);
         p_this->TestUnlock();
         t.Run();
         sleep(2);
      }
    }
    
    //尽量不要在构造函数内做有风险的事情
    void Init()
    {
      //锁和环境变量初始化
      pthread_mutex_init(&lock,nullptr);
      pthread_cond_init(&cond,nullptr);

      //线程池的创建
      pthread_t tid;
      for(int i=0;i<_max;i++)
      {
        pthread_create(&tid,nullptr,RunTest,this);//每个线程都去处理任务,不关心线程ID
      }
    }


      ~Pool()
      {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&cond);
      }


};
