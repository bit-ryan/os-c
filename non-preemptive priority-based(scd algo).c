#include <stdio.h>

struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void sortByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        if (processes[i].waitingTime < 0) {
            processes[i].waitingTime = 0;
        }

        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processId, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].priority, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\n");
}

int main() {
    struct Process processes[10];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
    }

    // Sort processes by priority
    sortByPriority(processes, n);

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n);

    // Display results
    displayResults(processes, n);

    return 0;
}
