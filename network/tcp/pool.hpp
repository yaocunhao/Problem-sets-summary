#pragma once
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <queue>
#include <unistd.h>
#include <map>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;
#define NUM 5

class Task
{
  private:
    int sock;
    map<string,string>dict;
  public:
    Task()
    {}

    Task(int _sock)
       :sock(_sock)
    {
      dict.insert(make_pair("banana","香蕉"));
      dict.insert(make_pair("apple","苹果"));
    }

    void Run()//来一个链接，执行一个任务(打印语句)
    {
      cout<<"Task is run....."<<endl;
      
      char buff[100];
      size_t size=recv (sock,buff,sizeof(buff)-1,0);
      if(size>0)//读取到了
      {
        buff[size]='\0';//末尾添加\0
        string key=buff;

        send(sock,dict[key].c_str(),dict[key].size(),0);//不需要+1，\0是语言的标准，文件不认识
      }
      else if(size==0)
      {
        cout<<"client quit..."<<endl;
        close(sock);//关闭对应的套接字
      }
      else//读取错误
      {
        cerr<<"read error"<<endl;
        close(sock);  
      }
    }



    ~Task()
    {
      close(sock);
    }
};


class Pool
{
  private:
    int _max;//线程个数
    queue<Task*> q;//存指针，减少数据拷贝消耗
    pthread_mutex_t lock;
    pthread_cond_t cond;

  public:
    
    Pool(int max=NUM)
      :_max(max)
    {}

    void TaskLock()
    {
      pthread_mutex_lock(&lock);
    }

    void TaskUnlock()
    {
      pthread_mutex_unlock(&lock);
     }

    void ThreadWait()
    {
      pthread_cond_wait(&cond,&lock);
    }

    void ThreadWakeUp()
    {
      pthread_cond_signal(&cond);//一次唤醒一个
    }

    void AllWakeUp()
    {
      pthread_cond_broadcast(&cond);//全部唤醒
    }


    bool IsEmpty()
    {
      return q.size()==0;
    }

    void Put(Task &data)//外部放入数据
    {
      TaskLock();
      q.push(&data);
      TaskUnlock();
      ThreadWakeUp();//唤醒一个线程
    }

    void Get(Task **data)//内部线程池完成任务
    {
      Task *t=q.front();
      q.pop();
      *data=t;
    }

public:

    //必须设置为静态的，因为成员函数会有this形参
    static void *RunTask(void *arg)//处理任务函数
    {
      Pool* p_this=(Pool*)arg;
      pthread_detach(pthread_self());//分离

      while(true)
      {
         p_this->TaskLock();
         //不退出才进行判断
         while(p_this->IsEmpty())//没有任务则挂起
         {
           p_this->ThreadWait();
         }

         //在这里一定不为空，将任务拿出来
         Task *t;
         p_this->Get(&t);

         p_this->TaskUnlock();
         t->Run();
         delete t;
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
        pthread_create(&tid,nullptr,RunTask,this);//每个线程都去处理任务,不关心线程ID
      }
    }

      ~Pool()
      {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&cond);
      }

};
