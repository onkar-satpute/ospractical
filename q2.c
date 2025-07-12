#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int pid, renice;
    printf("press ^Z to stop process\n");
    pid = fork();

    for(;;) { // Infinite loop
        if (pid == 0) { // Child process
            renice = nice(-5); // Increase priority (lower nice value)
            printf("Child gets higher CPU priority: %d\n", renice);
            sleep(2);
        } else { // Parent process
            renice = nice(4); // Decrease priority (higher nice value)
            printf("Parent gets lower CPU priority: %d\n", renice);
            sleep(1);
        }
    }

    return 0;
}