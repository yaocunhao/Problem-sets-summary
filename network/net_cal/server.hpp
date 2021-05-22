#pragma once
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
#include "protocol.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>

#define NUM 5

class Server
{
  private:
    int port;
    int lsock;

  public:
    Server(int _port)
      :port(_port)
       ,lsock(-1)
  {}
    
  void InitServer()
  {
    //创建套接字
    lsock=socket(AF_INET,SOCK_STREAM,0);
    if(lsock < 0)
    {
      cerr<<"lsock error!!"<<endl;
      exit(1);
    }

    //服务器绑定,填充服务器信息
    struct sockaddr_in ser_add;
    ser_add.sin_family=AF_INET;
    ser_add.sin_port=htons(port);
    ser_add.sin_addr.s_addr=INADDR_ANY;

    if(bind(lsock,(struct sockaddr*)&ser_add,sizeof(ser_add))< 0)
    {
      cerr<<"bind error"<<endl;
      exit(2);
    }
    
    
    //监听套接字
    if(listen(lsock,NUM)< 0)
    {
      cerr<<"listen error"<<endl;
      exit(3);
    }
  }

  void Cal(int sock)
  {
    cal ret;
    size_t size=recv(sock,&ret,sizeof(ret),0);
    if(size>0)
    {
      ret.code=0;
      switch(ret.op)
      {
        case'+':
          ret.result=ret.x+ret.y;
          break;
        case '-':
          ret.result=ret.x-ret.y;
          break;
        case'*':
          ret.result=ret.x*ret.y;
          break;
        case '/':
          if(ret.y==0)//除数不能为0
          {
            ret.code=1;
          }
          else
            ret.result=ret.x/ret.y;
          break;
        default:
          ret.code=2;//表示输入的操作数不符合
          break;
      }
    }
    send(sock,&ret,sizeof(ret),0);
    close(sock);//短链接
  }

  void start()
  {
     sockaddr_in peer;//获取对方信息
     socklen_t len =sizeof(peer);
     
     //建立链接
     while(true)
     {
        int sock=accept(lsock,(struct sockaddr*)&peer,&len); 
        if(sock < 0)
        {
          cerr<<"accept errot"<<endl;
          continue;
        }

        if(fork()==0)//子进程
        {
          if(fork() > 0)//子进程退出
            exit(0);

          close(lsock);//孙子进程关闭监听套接字
          Cal(sock);//调用任务函数
          exit(0);//短链接、调用完就退出
        }

        close(sock);
        waitpid(-1,nullptr,0);//等待任意子进程
     }
  }

    ~Server()
    {
      close(lsock);
    }



};
