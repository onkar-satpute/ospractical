#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t p;
    printf("before fork\n");
    p = fork();

    if (p == 0) { // child
        printf("Hello world\n");
        printf("I am child having id: %d\n", getpid());
        printf("My parent id is: %d\n", getppid());
    } else { // parent
        printf("\nHi\n");
        printf("My child id is: %d\n", p);
        printf("I am parent having id: %d\n", getpid());
    }

    return 0;
}