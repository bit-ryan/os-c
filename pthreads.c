#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4 // Adjust the number of threads as needed

// Structure to pass data to the thread function
struct ThreadData {
    int* array;
    int start;
    int end;
};

// Thread function to calculate the sum of a portion of the array
void* sumThread(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg;
    int sum = 0;

    for (int i = data->start; i < data->end; ++i) {
        sum += data->array[i];
    }

    // Return the sum through the pointer
    int* result = malloc(sizeof(int));
    *result = sum;
    return result;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];

    // Divide the array among threads
    int elementsPerThread = n / MAX_THREADS;

    // Create and launch threads
    for (int i = 0; i < MAX_THREADS; ++i) {
        threadData[i].array = array;
        threadData[i].start = i * elementsPerThread;
        threadData[i].end = (i == MAX_THREADS - 1) ? n : (i + 1) * elementsPerThread;

        pthread_create(&threads[i], NULL, sumThread, (void*)&threadData[i]);
    }

    // Wait for threads to finish and collect results
    int totalSum = 0;
    for (int i = 0; i < MAX_THREADS; ++i) {
        void* result;
        pthread_join(threads[i], &result);
        totalSum += *((int*)result);
        free(result);
    }

    printf("Sum of %d numbers: %d\n", n, totalSum);

    return 0;
}
