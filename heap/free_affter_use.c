#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct malloc_pr
{   
    int a;
    int b;
} malloc_pr_s;

void malloc_user(void ** use_addr, int *length)
{
    void * addr = NULL;

    // 堆上申请128个字节，并返回出函数
    addr = (void*)malloc(sizeof(malloc_pr_s));

    free(addr);

    // *use_addr = NULL;

    *use_addr = addr;

    printf("addr:%p\n", addr);
}


int main()
{

    malloc_pr_s *user_addr = NULL;
    int length = 0;

    malloc_user((void**)&user_addr, &length);

    // 打印申请的地址
    printf("user_addr:%p\n", user_addr);
    
    user_addr->a = 1;
    user_addr->b = 1;

    (user_addr + 1)->a = 333;
    (user_addr + 1)->b = 444;

    return 0;
}