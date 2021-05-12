#pragma once

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/inet.h>

class udpServer
{
  private:
    string ip;
    int port;
    int sock;

  public:
    udpServer(string _ip="127.0.1.1",int _port=7080)
      :ip(_ip)
       ,port(_port)
  {}


    void initServer()//初始化服务器
    {
      sock=socket(AF_INET,SOCK_DGRAM,0);
      cout<<sock<<endl;

      //当前套接字文件里面只有文件信息
      //这个文件对应的是网络文件、因此需要加入ip、port信息->绑定
      
      //传入的ip、port是在用户层的，下面需要绑定在内核里面
      //因此需要填充结构体，sockaddr_in(ipv4)
      
      struct sockaddr_in local;
      local.sin_family=AF_INET;//填充协议
      local.sin_port=htons(port);//填充端口->转成网络字节序
      local.sin_addr.in_addr::s_addr = inet_addr(ip.c_str());//转换的是字符串、不是类

      if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
      {
        cerr<<"bind error"<<endl;//往显示器上打印，但是对应的文件描述符不一样
        exit(1);//绑定失败终止整个进程
      }
    }

    //服务器启动之后、永不退出
    //写一个回应服务器
    void start()
    {
      while(1)
      {
        struct sockaddr_in end_point;//保存是谁送人信息->ip 和port
        socklen_t len=sizeof(end_point);//发送人结构体大小

        char buff[88];//接收消息缓冲区
        buff[0]='\0';//清空缓冲区

        ssize_t size=recvfrom(sock,buff,sizeof(buff)-1,0,(struct sockaddr*)&end_point,&len);//接收消息
        
        if(size>0)//收到消息了
        {
           buff[size]='\0';//在末尾添加\0
           cout<<"client send :"<<buff<<endl;
           
           string echo_string = buff;//回显字符串
           echo_string+="-> server echo";
           
          sendto(sock,echo_string.c_str(),echo_string.size(),0,(struct sockaddr*)&end_point,len);

        }
      }
    }

    ~udpServer()
    {
      close(sock);//关闭文件描述符
    }
    






};
