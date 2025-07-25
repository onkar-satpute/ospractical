#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sum = %d\n", sum);
    printf("Execution time = %f seconds\n", cpu_time_used);

    return 0;
}
