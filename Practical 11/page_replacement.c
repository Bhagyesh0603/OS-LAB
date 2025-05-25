#include <stdio.h>
#include <stdlib.h>

int fifo(int a[], int frame[], int n, int no) {
    int i, j = 0, k, avail, count = 0;
    for (i = 0; i < no; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        avail = 0;
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i])
                avail = 1;
        }
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
        }
    }
    return count;
}

int optimal(int a[], int frame[], int n, int no) {
    int i, j, k, pos, avail, count = 0, farthest;

    for (i = 0; i < no; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        avail = 0;
        for (j = 0; j < no; j++) {
            if (frame[j] == a[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            if (i < no) {
                frame[i] = a[i];
            } else {
                pos = -1;
                farthest = -1;
                for (j = 0; j < no; j++) {
                    int found = 0;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == a[k]) {
                            if (k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        pos = j;
                        break;
                    }
                }
                frame[pos] = a[i];
            }
            count++;
        }
    }
    return count;
}

int lru(int a[], int frame[], int n, int no) {
    int i, j, k, pos, avail, count = 0, least;
    int time[10] = {0};

    for (i = 0; i < no; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        avail = 0;
        for (j = 0; j < no; j++) {
            if (frame[j] == a[i]) {
                avail = 1;
                time[j] = i;
                break;
            }
        }

        if (avail == 0) {
            if (i < no) {
                frame[i] = a[i];
                time[i] = i;
            } else {
                least = time[0];
                pos = 0;
                for (j = 1; j < no; j++) {
                    if (time[j] < least) {
                        least = time[j];
                        pos = j;
                    }
                }
                frame[pos] = a[i];
                time[pos] = i;
            }
            count++;
        }
    }
    return count;
}

void main() {
    int a[] = {1, 3, 0, 3, 5, 6, 3};
    int frame[10], n = 7, no = 3;
    int i, j, k, fault, choice;

    do {
        printf("\n Page Replacement Menu \n");
        printf("1. FIFO\n");
        printf("2. Optimal\n");
        printf("3. LRU\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fault = fifo(a, frame, n, no);
            printf("Page Faults using FIFO: %d\n", fault);
            break;
        case 2:
            fault = optimal(a, frame, n, no);
            printf("Page Faults using Optimal: %d\n", fault);
            break;
        case 3:
            fault = lru(a, frame, n, no);
            printf("Page Faults using LRU: %d\n", fault);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter 1-4.\n");
        }
    } while (choice != 4);
}
