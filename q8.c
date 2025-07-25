#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int max[10];
    printf("Enter maximum resource need for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &max[i]);
    }

    // 🧮 Calculate total using the deadlock avoidance formula
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (max[i] - 1);
    }

    int min_resources = total + 1;

    printf("\nMinimum number of resources to avoid deadlock: %d\n", min_resources);

    return 0;
}
