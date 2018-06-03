#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *p1;
    char *p2;
    char *p3;
    char *p4;

    sleep(20);//让程序sleep 20s是因为我们程序先起来之后，等待SystemTap启动设置探测点

    p1 = malloc(500);

    p2 = malloc(200);

    p3 = malloc(300);

    p4 = malloc(300);//泄漏

    free(p1);

    free(p2);

    free(p3);

    free(p2);//重复释放

    printf("p1: %p, p2: %p, p3: %p, p4: %p\n", p1, p2, p3, p4);

    return 0;
}
