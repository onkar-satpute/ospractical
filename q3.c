#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p;
    p = fork();

    if (p == 0) {
        // Child process
        sleep(5); // Wait so that parent exits first
        printf("I am child having PID: %d\n", getpid());
        printf("My parent PID is: %d\n", getppid()); // Will show new parent: 'init' or 'systemd'
    } else if (p > 0) {
        // Parent process
        printf("I am parent having PID: %d\n", getpid());
        printf("My child PID is: %d\n", p);
    } else {
        perror("Fork failed");
    }

    return 0;
}