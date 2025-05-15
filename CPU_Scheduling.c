#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

void calculate_fcfs_times(Process processes[], int n) {
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_priority_times(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    calculate_fcfs_times(processes, n);
}

void calculate_round_robin_times(Process processes[], int n, int time_quantum) {
    int time = 0;
    bool done;

    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    do {
        done = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = false;

                if (processes[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = time;
                    processes[i].remaining_time = 0;
                }
            }
        }
    } while (!done);
}

void display_gantt_chart(Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].pid);
    }
    printf("|\n");

    printf("0");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        printf("   %d", time);
    }
    printf("\n");
}

int main() {
    int n, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].priority);
    }

    printf("\nSelect Scheduling Algorithm:\n");
    printf("1. Shortest Job First (SJF)\n");
    printf("2. First Come First Serve (FCFS)\n");
    printf("3. Priority Scheduling\n");
    printf("4. Round Robin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (processes[j].burst_time > processes[j + 1].burst_time) {
                    Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            }
        }
        calculate_fcfs_times(processes, n);
    } else if (choice == 2) {
        calculate_fcfs_times(processes, n);
    } else if (choice == 3) {
        calculate_priority_times(processes, n);
    } else if (choice == 4) {
        int time_quantum;
        printf("Enter the time quantum for Round Robin: ");
        scanf("%d", &time_quantum);
        calculate_round_robin_times(processes, n, time_quantum);
    } else {
        printf("Invalid choice! Exiting.\n");
        return 1;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    display_gantt_chart(processes, n);

    return 0;
}
