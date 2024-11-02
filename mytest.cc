#include <iostream>
#include <sys/types.h>
#include <unistd.h>

//我写了一个将来会一直运行的程序，用来进行后续的测试
int main()
{
    while(true)
    {
        std::cout << "我是一个正在运行的进程，pid: " << getpid() << std::endl;
        sleep(1);
    }
}