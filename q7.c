#include <stdio.h>

int main() {
    int process, resource;

    printf("Enter number of processes: ");
    scanf("%d", &process);
    printf("Enter number of resources: ");
    scanf("%d", &resource);

    int max[10][10], alloc[10][10], need[10][10];

    printf("\nEnter Max matrix:\n");
    for (int i = 0; i < process; i++) {
        for (int j = 0; j < resource; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Allocation matrix:\n");
    for (int i = 0; i < process; i++) {
        for (int j = 0; j < resource; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // 🔧 Calculate Need matrix: need = max - alloc
    for (int i = 0; i < process; i++) {
        for (int j = 0; j < resource; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed matrix:\n");
    for (int i = 0; i < process; i++) {
        for (int j = 0; j < resource; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
