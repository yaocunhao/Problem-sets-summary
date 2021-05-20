#ifndef _TCPSERVER_HPP_
#define _TCPSERVER_HPP_

#include "pool.hpp"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

#endif

#define BACKLOCK 5

class tcpServer
{
  private:
    int port;
    int lsock;//监听套接字
    Pool *pl;
  
  public:
    tcpServer(int _port)
      :port(_port)
       ,lsock(-1)
       ,pl(nullptr)
    {}

    void initServer()
    {
      signal(SIGCHLD,SIG_IGN);//父进程忽略子进程发送过来的信号，即子进程自己清理资源

      lsock=socket(AF_INET,SOCK_STREAM,0);
      if(lsock<0)
      {
        cerr<<"socket fail"<<endl;
        exit(2);
      }
      
      struct sockaddr_in local;
      local.sin_family=AF_INET;//填充协议
      local.sin_port=htons(port);//填充端口，转换成网网络字节序
      local.sin_addr.s_addr=INADDR_ANY;//填写ip
    
      if(bind(lsock,(struct sockaddr*)&local,sizeof(local))<0)//进行绑定
      {
        cerr<<"bind error"<<endl;
        exit(3);
      }
      if(listen(lsock,BACKLOCK)<0)
      {
        cerr<<"listen error"<<endl;
        exit(4);
      }
      pl=new Pool();
      pl->Init();//初始化线程池
    }

    static void service(int sock)
    {
      char buff[200];
      while(true)
      {
        size_t size=recv (sock,buff,sizeof(buff)-1,0);
        if(size>0)//读取到了
        {
          buff[size]='\0';//末尾添加\0
          cout<<"client:"<<buff<<endl;

          send(sock,buff,strlen(buff),0);//不需要+1，\0是语言的标准，文件不认识
        }
        else if(size==0)
        {
          cout<<"client quit..."<<endl;
          close(sock);//关闭对应的套接字
          break;
        }
        else//读取错误
        {
          cerr<<"read error"<<endl;
          close(sock);
          break;
        }
      }
    }


    static void *sevrun(void *arg)//只能有一个参数，因此必须是static
    {
      pthread_detach(pthread_self());//线程分离
      cout<<"create a new prhread"<<endl;
      int *p=(int*)arg;
      int sock=*p;
      service(sock);//执行任务
      delete p;
      return NULL;
    }

    void stat()
    {
      sockaddr_in end_point;//获取客户结构体信息，和udp作用一样
      while(true)
      {
        //udp直接通信，tcp第一件事是获取链接
        socklen_t len=sizeof(end_point);
        int sock=accept(lsock,(struct sockaddr*)&end_point,&len);
        if(sock<0)
        {
          cerr<<"accpet error"<<endl;
          continue;
        }

        string cl;//客户端信息
        cl+=inet_ntoa(end_point.sin_addr);//网->主，整->字符串
        cl+=':';
        cl+=to_string(ntohs(end_point.sin_port));

        cout<<"get a new accept:"<<cl<<"-"<<"sock:"<<sock<<endl;
      
      //此时获得了新的连接 -> 将任务put至线程池
        Task *t= new Task(sock);
        pl->Put(*t);//将任务put进去

      }
    }

  ~tcpServer()
  {
    close(lsock);
  }

};
