#pragma once
#include <iostream>
using namespace std;
#include <pthread.h> 
#include <queue>
#define NUM 6
#include <unistd.h>
class H2O 
{
private:
//H、O数量
int _num_o;
int _num_h;

queue<char> _q;
int _cap;

pthread_mutex_t lock;
pthread_cond_t o_cond;
pthread_cond_t h_cond;

public:

H2O(int num=0)
  :_cap(NUM)
   ,_num_o(num)
   ,_num_h(num)
{}

void Init()
{
//初始化锁和条件变量
	pthread_mutex_init(&lock,nullptr);
	pthread_cond_init(&o_cond,nullptr);
	pthread_cond_init(&h_cond,nullptr);

//创建线程池
	pthread_t tid1;
	pthread_t tid2;
		pthread_create(&tid1,nullptr,hydrogen,this);
		pthread_create(&tid2,nullptr,oxygen,this);
}

void Lock()
{
  pthread_mutex_lock(&lock);
}

void ULock()
{
  pthread_mutex_unlock(&lock);
}

void Wait(pthread_cond_t &cond)
{
  pthread_cond_wait(&cond,&lock);
}

void WakeUP(pthread_cond_t &cond)
{
  pthread_cond_signal(&cond);
}

void WakeUpThread()
{
  pthread_cond_signal(&o_cond);
  pthread_cond_signal(&h_cond);
}

bool Empty()
{
  return _q.empty();
}

bool Full()
{
  return (int)_q.size()>=_cap;
}

void releaseOxygen()//生产O
{
	while(1)	
	{
		Lock();
    
    if(Full())//满了全部挂起
    Wait(o_cond);

		while(_num_h==0||_num_o>=1)//每次生产一个,H先生产
		{
      WakeUP(h_cond);
			Wait(o_cond);
		}
		_q.push('O');
		_num_o++;

    ULock();
  }
}

void releaseHydrogen()//生产H
{
  while(1)
  {
    Lock();
    if(Full())
      Wait(h_cond);

    while(_num_h>=2)
    {
      WakeUP(o_cond);
      Wait(h_cond);
    }
    _q.push('H');
    _num_h++;
    ULock();
  }
}

  static void* hydrogen(void *arg) //生产H
{
  pthread_detach(pthread_self());//线程分离
  H2O *h=(H2O*)arg;
	h->releaseHydrogen();
  return NULL;
}

  static void *oxygen(void *arg)//生产O 
{
  pthread_detach(pthread_self());//线程分离
  H2O *h=(H2O*)arg;
  h->releaseOxygen();
  return NULL;
}

void Take(char &data)//拿水分子
{
   Lock();
  if(!Empty())
  {
    data=_q.front();
    _q.pop();
    if(data=='H')
      _num_h--;
    else
      _num_o--;
  }
  WakeUpThread();
  
  ULock();  
}
  
};

