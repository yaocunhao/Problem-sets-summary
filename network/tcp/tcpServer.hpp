#ifndef _TCPSERVER_HPP_
#define _TCPSERVER_HPP_

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>

#endif

#define BACKLOCK 5


class tcpServer
{
  private:
    int port;
    int lsock;//监听套接字
  public:
    tcpServer(int _port)
      :port(_port)
       ,lsock(-1)
    {}

    void initServer()
    {
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
    }

    void service(int sock)
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
      }
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
        cout<<"get a new accept"<<endl;
        service(sock);//封装一个服务接口
        
      }
    }

  


  ~tcpServer()
  {}

};
