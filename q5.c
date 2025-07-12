#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *command = "ls";
    char *argument_list[] = {"ls", "-l", NULL};

    printf("Before calling execvp.\n");

    pid_t pid = fork(); // Create a child process

    if (pid == 0) {
        // Child process
        printf("Child: PID %d, Parent PID %d\n", getpid(), getppid());
        int status_code = execvp(command, argument_list);

        // This line only runs if execvp fails
        if (status_code == -1) {
            perror("Exec failed");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        sleep(10); // Delay so child executes first
        printf("Parent: This line is printed after sleep.\n");
    } else {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}