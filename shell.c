#include "user.h"
int create_thread(void *func) {
    // 透過 ecall
    register long a0 __asm__("a0") = (long) func;
    register long a3 __asm__("a3") = SYS_CREATE_THREAD;
    __asm__ volatile("ecall" : "=r"(a0) : "r"(a0), "r"(a3));
    return (int) a0; // 回傳 tid
}
void yield(void) {
    register long a3 __asm__("a3") = SYS_YIELD;
    __asm__ volatile("ecall" : : "r"(a3));
}

void test_user_thread() {
    while(1) {
        printf("\nHello from user thread!\n");
        yield();
    }
    return ;
}
int main(void) {
    printf("before create_thread in shell.c\n");
    create_thread(test_user_thread);
    while(1) {
        printf("Hello from main thread!\n");
        yield();
    }
    printf("are you pao wan");
    return 0;
}