// Program to implement Worst fit memory allocation algorithm.
// Bhumika Jadhav (SY_B_10)

#include <stdio.h>

int main() {
    int b_no, p_no;

    printf("Enter number of blocks: ");
    scanf("%d", &b_no);

    int size[b_no], flags[b_no], allocation[b_no], temp;

    printf("Enter sizes of blocks:\n");
    for (int i = 0; i < b_no; i++) {
        scanf("%d", &size[i]);
        flags[i] = 0;
        allocation[i] = -1;
    }

    printf("Enter number of processes: ");
    scanf("%d", &p_no);

    int psize[p_no];
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < p_no; i++) {
        scanf("%d", &psize[i]);
    }

    for (int i = 0; i < b_no - 1; i++) {
        for (int j = 0; j < b_no - i - 1; j++) {
            if (size[j] < size[j + 1]) {

                temp = size[j];
                size[j] = size[j + 1];
                size[j + 1] = temp;

                temp = flags[j];
                flags[j] = flags[j + 1];
                flags[j + 1] = temp;

                temp = allocation[j];
                allocation[j] = allocation[j + 1];
                allocation[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < p_no; i++) {
        for (int j = 0; j < b_no; j++) {
            if (flags[j] == 0 && size[j] >= psize[i]) {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }

    printf("\nBlock no\tSize\t\tProcess no\tPsize\n");
    for (int i = 0; i < b_no; i++) {
        printf("%d\t\t%d\t\t", i + 1, size[i]);
        if (flags[i] == 1) {
            printf("%d\t\t%d\n", allocation[i] + 1, psize[allocation[i]]);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}

