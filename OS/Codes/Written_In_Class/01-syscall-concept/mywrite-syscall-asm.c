#include <stdio.h>

long mywrite(int fd, const void *buf, unsigned long count)
{
    long ret;

    __asm__ volatile ("movq $1, %%rax" :: : "rax");
    __asm__ volatile ("movq %0, %%rdi" :: "r"((long)fd) : "rdi");
    __asm__ volatile ("movq %0, %%rsi" :: "r"(buf) : "rsi");
    __asm__ volatile ("movq %0, %%rdx" :: "r"(count) : "rdx");

    __asm__ volatile (
        "syscall"
        : "=a"(ret)
        :
        : "rcx", "r11", "memory"
    );

    return ret;
}
int main(void)
{
    long ret = mywrite(1, "a", 1);

    printf("\nmywrite() returned %ld\n", ret);

    return 0;
}
