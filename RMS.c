#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int execution_time;
    int period;
    int remaining_time;
} Task;

void sortByPeriod(Task tasks[], int n) {
    Task temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].period > tasks[j].period) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    Task tasks[MAX];
    int n, hyperperiod = 1;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        tasks[i].id = i + 1;
        printf("Execution Time: ");
        scanf("%d", &tasks[i].execution_time);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        tasks[i].remaining_time = 0;

        hyperperiod *= tasks[i].period; // simple hyperperiod (not LCM for simplicity)
    }

    // Sort tasks by period (priority)
    sortByPeriod(tasks, n);

    printf("\nScheduling Order (Time vs Task):\n");

    for (int t = 0; t < hyperperiod; t++) {

        // Release tasks at their period
        for (int i = 0; i < n; i++) {
            if (t % tasks[i].period == 0) {
                tasks[i].remaining_time = tasks[i].execution_time;
            }
        }

        int task_executed = -1;

        // Select highest priority task
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                task_executed = i;
                break;
            }
        }

        if (task_executed != -1) {
            printf("Time %d: Task %d\n", t, tasks[task_executed].id);
            tasks[task_executed].remaining_time--;
        } else {
            printf("Time %d: Idle\n", t);
        }
    }

    return 0;
}
