#include <stdio.h>

struct process {
    int pid;
    int arrival;
    int btime;
    int remaining;
    int wtime;
    int ttime;
    int completion_time;
    int completed_order;
} p[10];

void main() {
    int i, j, n, time = 0, completed = 0, time_slot;
    int total_wtime = 0, total_ttime = 0;
    float awat, atur;
    int completion_order = 1;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter Details of Process %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].remaining = p[i].btime;
        p[i].wtime = 0;
        p[i].ttime = 0;
        p[i].completion_time = 0;
        p[i].completed_order = 0;
    }

    printf("\nEnter Time Slot: ");
    scanf("%d", &time_slot);

    // Round Robin Scheduling
    while(completed < n) {
        int active = 0;
        for(i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                active = 1;
                if(p[i].remaining > time_slot) {
                    time += time_slot;
                    p[i].remaining -= time_slot;
                } else {
                    time += p[i].remaining;
                    p[i].wtime = time - p[i].arrival - p[i].btime;
                    p[i].ttime = time - p[i].arrival;
                    p[i].remaining = 0;
                    p[i].completion_time = time;
                    p[i].completed_order = completion_order++;
                    completed++;
                }
            }
        }
        if(!active) time++; // No process ready, just increment time
    }

    // Sort processes by completion order
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p[j].completed_order > p[j+1].completed_order) {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calculate totals
    for(i = 0; i < n; i++) {
        total_wtime += p[i].wtime;
        total_ttime += p[i].ttime;
    }

    awat = (float)total_wtime / n;
    atur = (float)total_ttime / n;

    // Print results
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting time\n");
    for(i = 0; i < n; i++) {
        printf("Process No %d\t%d\t\t%d\t\t%d\n", 
               p[i].pid, p[i].btime, p[i].ttime, p[i].wtime);
    }

    printf("\nAverage Waiting Time: %f", awat);
    printf("\nAverage Turnaround Time: %f\n", atur);
}