//Program to implement Quick Sort using multiple threads
//Bhumika Jadhav (SY_B_10)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define MAX 1000000

int arr[MAX];
int temp_arr[MAX];
int pivot_index;

int partition(int low, int high, int* array) {
    int pivot = array[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && array[i] <= pivot) i++;
        while (array[j] > pivot) j--;

        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}

void quick_sort(int low, int high, int* array) {
    if (low < high) {
        int pi = partition(low, high, array);
        quick_sort(low, pi - 1, array);
        quick_sort(pi + 1, high, array);
    }
}

typedef struct {
    int low;
    int high;
    int* array;
} ThreadArgs;

void* quick_sort_thread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    quick_sort(args->low, args->high, args->array);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++)
        temp_arr[i] = rand() % 100;

    int arr_single[MAX];
    for (int i = 0; i < MAX; i++)
        arr_single[i] = temp_arr[i];

    clock_t start_single = clock();
    quick_sort(0, MAX - 1, arr_single);
    clock_t end_single = clock();

    double time_single = ((double)(end_single - start_single)) / CLOCKS_PER_SEC;

    int arr_multi[MAX];
    for (int i = 0; i < MAX; i++)
        arr_multi[i] = temp_arr[i];

    pivot_index = partition(0, MAX - 1, arr_multi);

    pthread_t t1, t2;
    ThreadArgs args1 = {0, pivot_index - 1, arr_multi};
    ThreadArgs args2 = {pivot_index + 1, MAX - 1, arr_multi};

    clock_t start_multi = clock();

    pthread_create(&t1, NULL, quick_sort_thread, &args1);
    pthread_create(&t2, NULL, quick_sort_thread, &args2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    clock_t end_multi = clock();

    double time_multi = ((double)(end_multi - start_multi)) / CLOCKS_PER_SEC;

    printf("\nPerformance Analysis \n");
    printf("Single-threaded time: %.4f seconds\n", time_single);
    printf("Two-threaded time : %.4f seconds\n", time_multi);
    printf("Speedup : %.2fx faster\n", time_single / time_multi);

    return 0;
}
