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

class udpClient
{
  private:
    string ip;
    int port;
    int sock;

  public:
    //连接服务器->所以填写server的ip和端口-> 下载软件的时候就是下载客户端
    udpClient(string _ip,int _port)
      :ip(_ip)
       ,port(_port)
  {}


    void initClient()//初始化客户端
    {
      sock=socket(AF_INET,SOCK_DGRAM,0);
      cout<<sock<<endl;

      //客户端不需要绑定
    }

    //服务器启动之后、永不退出
    //写一个回应服务器
    void start()
    {
      string send_string;
      //发送给谁，填充信息
      struct sockaddr_in peer;
      peer.sin_family=AF_INET;
      peer.sin_port=htons(port);
      peer.sin_addr.s_addr=inet_addr(ip.c_str());//将字符串转成4字节再转成网络字节序

      
      
      char buff[88];

      while(1)
      {
        cout<<"please enter your message#"<<endl;
        getline(cin,send_string);

        sendto(sock,send_string.c_str(),send_string.size(),0,(struct sockaddr*)&peer,sizeof(peer));
        
        buff[0]='\0';
        ssize_t size=recvfrom(sock,buff,sizeof(buff)-1,0,nullptr,nullptr);
        if(size>0)
        {
          buff[size]='\0';
          cout<<"Serve:"<<buff<<endl;
        }

      }

    }

    ~udpClient()
    {
      close(sock);//关闭文件描述符
    }
    






};
