#pragma once
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <vector>
#define  NUM 5

class RingQueue
{
  private:
    std::vector<int> _q;
    int _cap;
    //信号量
    sem_t sem_blank;
    sem_t sem_data;
  //资源下标
    int pro_sub;
    int con_sub;

  private:
    void P(sem_t &sem)
    {
      sem_wait(&sem);
    }

    void V(sem_t &sem)
    {
      sem_post(&sem);
    }


  public:
  RingQueue(int cap=NUM)
    :_cap(cap)
     ,_q(cap)
  {
    sem_init(&sem_blank,0,_cap);//格子个数一开始为容量大小
    sem_init(&sem_data,0,0);//数据一开始为0
    pro_sub=0;
    con_sub=0;
  }
  
  void Put(const int &data)
  {
    P(sem_blank);//申请格子资源，判断是否还有容量，格子--
    _q[pro_sub]=data;
    pro_sub++;
    pro_sub%=_cap;//越界回环
    V(sem_data);//数据++
  }

  void Get(int &data)
  {
    P(sem_data);//申请数据资源,判断是否还有数据，数据--
    data=_q[con_sub];
    con_sub++;
    con_sub%=_cap;
    V(sem_blank);//消耗数据，格子++
  }

  ~RingQueue()
  {
    sem_destroy(&sem_blank);
    sem_destroy(&sem_data);
    pro_sub=con_sub=0;
  }

};

