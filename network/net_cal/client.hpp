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

class Client
{
  private:
    string ip;
    int port;
    int sock;

  public:
    Client(string _ip,int _port)
      :ip(_ip)
      ,port(_port)
       ,sock(-1)
  {}
    
  void InitClient()
  {
    //创建套接字
    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
      cerr<<"sock error!!"<<endl;
      exit(1);
    }
  }


  void start()
  {
    //发送给谁、填写信息
    sockaddr_in ser_add;
    ser_add.sin_family=AF_INET;
    ser_add.sin_addr.s_addr=inet_addr(ip.c_str());//字符串转成网络整形
    ser_add.sin_port=htons(port);

    if(connect(sock,(struct sockaddr*)&ser_add,sizeof(ser_add))!=0)
    {
      cerr<<"connect error"<<endl;
      exit(2);
    }

    //链接成功，发送信息
    cal mes;
    cout<<"please enter one num:";
    cin>>mes.x;
    cout<<"please enter two num:";
    cin>>mes.y;
    cout<<"please enter op:";
    cin>>mes.op;

    send(sock,&mes,sizeof(mes),0);
    recv(sock,&mes,sizeof(mes),0);

    cout<<"code:"<<mes.code<<" "<<"result:"<<mes.result<<endl;
  }

  ~Client()
  {
    close(sock);
  }
};
