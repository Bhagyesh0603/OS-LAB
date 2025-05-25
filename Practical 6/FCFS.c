// Program to implement FCFS scheduling algorithm
// Bhumika Jadhav (SY_B_10)

#include <stdio.h>

int main() {
    int n, bt[20], tat[20], wt[20], tot_wt = 0, tot_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes for FCFS scheduling:\n");
    scanf("%d", &n);

    printf("Enter the burst time of %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\n\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tot_wt += wt[i],tot_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n");

    avg_wt = (float)tot_wt / n;
    avg_tat = (float)tot_tat / n;

    printf("Average waiting time is: %.2f\n", avg_wt);
    printf("Average turn around time is: %.2f\n", avg_tat);

    return 0;
}
