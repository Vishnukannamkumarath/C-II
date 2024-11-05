#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;          // Process ID
    int burst_time;   // Burst time of the process
};

// Function to perform SJF scheduling
void sjfScheduling(struct Process proc[], int n) {
    int time = 0;    // Current time
    int completed = 0; // Number of completed processes

    while (completed < n) {
        int shortest = -1; // Index of the shortest job
        int min_burst = INT_MAX;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (proc[i].burst_time > 0 && proc[i].burst_time < min_burst && time >= proc[i].arrival_time) {
                shortest = i;
                min_burst = proc[i].burst_time;
            }
        }

        if (shortest == -1) {
            time++; // No process is ready, so increment time
        } else {
            // Execute the shortest job
            proc[shortest].burst_time--;
            time++;

            // If burst time becomes 0, mark the process as completed
            if (proc[shortest].burst_time == 0) {
                completed++;
                printf("Process %d completed at time %d\n", proc[shortest].pid, time);
            }
        }
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n]; // Array of processes

    // Input the details of each process
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        proc[i].pid = i + 1;
        printf("Enter burst time: ");
        scanf("%d", &proc[i].burst_time);
    }

    // Call the SJF scheduling function
    sjfScheduling(proc, n);

    return 0;
}

