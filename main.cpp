#include "ClusterManager.h"
#include "cli_client.h"

int main()
{
    CCliUdpClient::instance()->setSerInf("192.168.85.255", 9000);
    int sendNum = CCliUdpClient::instance()->send("help\r\n", 7);
    printf("sendNum  %d\n", sendNum);
    return 0;
}

