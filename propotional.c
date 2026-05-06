#include <stdio.h>

// Structure for a task
typedef struct {
    int id;
    float execution_time; // Ci
    float period;         // Ti
    float share;          // Ci / Ti
} Task;

int main() {
    int n;
    float total_share = 0.0;

    printf("--- Proportional Scheduling ---\n");
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    // Input
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nFor Task P%d:\n", tasks[i].id);

        printf(" Enter Execution Time (Ci): ");
        scanf("%f", &tasks[i].execution_time);

        printf(" Enter Period (Ti): ");
        scanf("%f", &tasks[i].period);

        // Compute share
        tasks[i].share = tasks[i].execution_time / tasks[i].period;
        total_share += tasks[i].share;
    }

    // Output
    printf("\n--- Results ---\n");

    for (int i = 0; i < n; i++) {
        printf("Task P%d Share: %.4f\n", tasks[i].id, tasks[i].share);
    }

    printf("Total CPU Share: %.4f\n", total_share);

    // Schedulability condition
    if (total_share <= 1.0) {
        printf("SCHEDULABLE (CPU can be proportionally allocated)\n");
    } else {
        printf("NOT SCHEDULABLE (Total share exceeds CPU capacity)\n");
    }

    return 0;
}