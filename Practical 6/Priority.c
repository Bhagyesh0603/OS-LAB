// Program to implement Priority scheduling algorithm.
// Bhumika Jadhav (SY_B_10)

#include <stdio.h>
#include <stdlib.h>

float bt[5], wt[5], tat[5], avg_tat, avg_wt, temp1, tot_wt = 0, tot_tat = 0;
int n, i, j, temp2, priority[5];

int main() {
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    printf("Enter burst time of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &bt[i]);
    }

    printf("Enter priority of %d processes (smaller number = higher priority):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {

                temp2 = priority[i];
                priority[i] = priority[j];
                priority[j] = temp2;

                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\n\tBT\tPrt\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tot_wt += wt[i];
        tot_tat += tat[i];
        printf("P%d\t%.2f\t%d\t%.2f\t%.2f\n", i + 1, bt[i], priority[i], wt[i], tat[i]);
    }
    printf("\n");
    avg_wt = tot_wt / n;
    avg_tat = tot_tat / n;

    printf("Average waiting time is: %.2f\n", avg_wt);
    printf("Average turnaround time is: %.2f\n", avg_tat);

    return 0;
}

