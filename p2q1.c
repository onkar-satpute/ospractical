#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define IO_WAIT_TIME 2

void calculateTimes(int n, int arrival[], int burst[], int process[]) {
    int completion[n], turnaround[n], waiting[n];
    int current_time = 0, completed = 0;
    bool is_completed[n];
    float total_turnaround = 0, total_waiting = 0;
    int i, idx, min_burst;

    for (i = 0; i < n; i++)
        is_completed[i] = false;

    printf("\nGantt Chart: ");

    while (completed < n) {
        idx = -1;
        min_burst = INT_MAX;

        for (i = 0; i < n; i++) {
            if (arrival[i] <= current_time && !is_completed[i] && burst[i] < min_burst) {
                min_burst = burst[i];
                idx = i;
            }
        }

        if (idx != -1) {
            printf("P%d(%d-%d) ", process[idx], current_time, current_time + burst[idx]);

            current_time += burst[idx];
            completion[idx] = current_time;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            total_turnaround += turnaround[idx];
            total_waiting += waiting[idx];
            is_completed[idx] = true;
            completed++;

            current_time += IO_WAIT_TIME + (rand() % 10 + 1); // I/O wait + next burst
        } else {
            current_time++;
        }
    }

    printf("\n\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_turnaround / n);
    printf("\nAverage Waiting Time: %.2f\n", total_waiting / n);
}

int main() {
    int n;
    int i;

    srand(time(0)); 

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], process[n];

    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival and burst time for process P%d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    calculateTimes(n, arrival, burst, process);

    return 0;
}
