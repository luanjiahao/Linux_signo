#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <string>
#include <signal.h>
#include <sys/types.h>

using namespace std;

static void Usage(const std::string &proc)
{
    std::cout << "\nUsage: " << proc << " pid signo\n"
              << std::endl;
}

void catchSig(int signo)
{
    std::cout << "获取到一个信号，信号编号是: " << signo << std::endl;
    exit(1);
    // alarm(1);
}

int main(int argc, char *argv[])
{
    signal(11, catchSig);
    while (true)
    {
        std::cout << "我在运行中...." << std::endl;
        sleep(1);
        // int a = 10;
        // a /= 0;
        int *p = nullptr;
        *p = 100;
    }

    // about() 与 raise()的使用
    int cnt = 0;
    while (cnt <= 10)
    {
        printf("cnt: %d, pid: %d\n", cnt++, getpid());
        sleep(1);
        if (cnt >= 5)
            abort(); // about()给自己发送指定信号(6) 等价于 kill(getpid(), SIGABRT)
        if (cnt >= 5)
            raise(9); // raise()自己给自己发信号 等价于 kill(getpid(), signo)
    }

    // kill()函数的使用
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    pid_t pid = atoi(argv[1]); // atoi是 C/C++ 语言中的一个函数，用于将字符串转换为整数。
    int signo = atoi(argv[2]);
    int n = kill(pid, signo);
    if (n != 0)
    {
        perror("kill");
    }
}