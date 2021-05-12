#include "udpClient.hpp"

int main()
{
  udpClient *uc =new udpClient;
  uc->initClient();
  uc->start();
  return 0;
}
