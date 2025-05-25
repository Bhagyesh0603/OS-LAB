// C program to find a solution for the Producer-Consumer problem using semaphores
// Bhumika Prasad Jadhav (SY_B_10)

#include <stdio.h>
#include <stdlib.h>

int s = 1, full = 0, empty = 10, x = 0;

void wait(int s) {
    while (s <= 0);
    s--;
}

void signal(int s) {
    s++;
}

void producer() {
    wait(s);
    ++full;
    --empty;
    x++;
    printf("\nProducer Produces item %d", x);
    signal(s);
}

void consumer() {
    wait(s);
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", x);
    x--;
    signal(s);
}

int main() {
    int i, n;
    printf("Choices are:\n1: Producer\n2: Consumer\n3: Exit\n");

    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((s == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full\n");
                }
                break;

            case 2:
                if ((s == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty\n");
                }
                break;

            case 3:
                exit(0);
        }
    }

    return 0;
}

