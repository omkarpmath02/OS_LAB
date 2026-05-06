#include <stdio.h>

// Structure for a task
typedef struct {
    int id;
    float burst_time;   // Ci
    float period;       // Ti (also deadline Di in EDF)
    float utilization;  // Ci / Ti
} Task;

int main() {
    int n;
    float total_utilization = 0.0;

    printf("--- Earliest Deadline First (EDF) Scheduling ---\n");
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    // Input
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nFor Task P%d:\n", tasks[i].id);

        printf(" Enter Burst Time (Ci): ");
        scanf("%f", &tasks[i].burst_time);

        printf(" Enter Period / Deadline (Ti = Di): ");
        scanf("%f", &tasks[i].period);

        // Utilization
        tasks[i].utilization = tasks[i].burst_time / tasks[i].period;
        total_utilization += tasks[i].utilization;
    }

    printf("\n--- Results ---\n");
    printf("Total CPU Utilization (U): %.4f\n", total_utilization);

    // EDF Condition
    if (total_utilization <= 1.0) {
        printf("SCHEDULABLE (EDF guarantees scheduling)\n");
    } else {
        printf("NOT SCHEDULABLE (CPU overloaded, U > 1.0)\n");
    }

    return 0;
}