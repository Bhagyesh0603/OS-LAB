//C program to implement Banker's algorithm
//Bhumika Jadhav (SY_B_10)

#include <stdio.h>
#include <stdbool.h>
#define n 3
#define m 3

int main() {
    int alloc[n][m] = {
        {2, 1, 0},
        {1, 2, 2},
        {0, 2, 0}
    };

    int max[n][m] = {
        {3, 2, 2},
        {2, 4, 3},
        {2, 3, 1}
    };

    int avail[m] = {2, 1, 1};

    int need[n][m], finish[n] = {0}, work[m], safe[n], count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    safe[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    printf("\n");

    if (count == n) {
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d%s", safe[i], (i == n - 1) ? "\n" : " -> ");
    } else {
        printf("System is not in a safe state.\n");
    }

    return 0;
}

