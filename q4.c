#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *command = "/bin/ls";  // Full path improves reliability
    char *argument_list[] = {"ls", "-l", "/home", NULL};

    printf("Before calling exec()\n");

    pid_t pid = fork(); // Create a child process

    if (pid == 0) {
        // In child process
        printf("I am child. My PID: %d, Parent PID: %d\n", getpid(), getppid());
        int status_code = execvp(command, argument_list);

        if (status_code == -1) {
            perror("Exec failed");
        }
    } else if (pid > 0) {
        // In parent process
        printf("I am parent. My PID: %d, Child PID: %d\n", getpid(), pid);
    } else {
        // Fork failed
        perror("Fork failed");
    }

    return 0;
}