#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculateTimes(int n, int arrival_time[], int burst_time[], int io_wait_time) {
    int completion_time[n], turnaround_time[n], waiting_time[n];
    int current_time = 0;
    float total_turnaround_time = 0, total_waiting_time = 0;
    int i;

    printf("\nGantt Chart: ");

    for (i = 0; i < n; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }

        printf("P%d(%d-%d) ", i + 1, current_time, current_time + burst_time[i]);

        current_time += burst_time[i];
        completion_time[i] = current_time;
        current_time += io_wait_time;
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_turnaround_time += turnaround_time[i];
        total_waiting_time += waiting_time[i];
    }

    printf("\n\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_turnaround_time / n);
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
}

int main() {
    int n, io_wait_time = 2;
    int i;
    int *arrival_time, *burst_time;

    srand(time(0));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    arrival_time = (int *)malloc(n * sizeof(int));
    burst_time = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter first CPU burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    calculateTimes(n, arrival_time, burst_time, io_wait_time);

    free(arrival_time);
    free(burst_time);

    return 0;
}
