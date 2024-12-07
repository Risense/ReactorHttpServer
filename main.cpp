#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "TcpServer.h"

int main(int argc, char* argv[])
{
#if 1
    if (argc < 3)
    { 
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    chdir(argv[2]);
#else
    unsigned short port = 10086;  
    chdir("/home/risen/data"); // 切换服务器的工作路径
#endif
    // 启动服务器
    TcpServer* server = new TcpServer(port, 4); // 传递端口和线程池中的子线程个数
    server->run();
    printf("server is running...\n");
    return 0;
}