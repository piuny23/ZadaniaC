#include <stdio.h>

#define SIZE 10

void printArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
}

int findMaximum(int numbers[], int size) {
    int max = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

int findMinimum(int numbers[], int size) {
    int min = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return min;
}

int calculateSum(int numbers[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    return sum;
}

float calculateAverage(int numbers[], int size) {
    int sum = calculateSum(numbers, size);
    return (float) sum / size;
}

void swapMinAndMax(int numbers[], int size) {
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }

        if (numbers[i] > numbers[maxIndex]) {
            maxIndex = i;
        }
    }

    int temp = numbers[minIndex];
    numbers[minIndex] = numbers[maxIndex];
    numbers[maxIndex] = temp;
}

void copyArray(int source[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = source[i];
    }
}

void sortArray(int numbers[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

float calculateMedian(int numbers[], int size) {
    int sorted[SIZE];

    copyArray(numbers, sorted, size);
    sortArray(sorted, size);

    if (size % 2 == 0) {
        return (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
    }

    return sorted[size / 2];
}

int main() {
    int numbers[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};
    int sorted[SIZE];

    printf("Original array:\n");
    printArray(numbers, SIZE);

    printf("\nMaximum: %d\n", findMaximum(numbers, SIZE));
    printf("Minimum: %d\n", findMinimum(numbers, SIZE));
    printf("Sum: %d\n", calculateSum(numbers, SIZE));
    printf("Average: %.2f\n", calculateAverage(numbers, SIZE));

    printf("\nArray after swapping minimum and maximum:\n");
    swapMinAndMax(numbers, SIZE);
    printArray(numbers, SIZE);

    copyArray(numbers, sorted, SIZE);
    sortArray(sorted, SIZE);

    printf("\nSorted array:\n");
    printArray(sorted, SIZE);

    printf("\nMedian: %.2f\n", calculateMedian(numbers, SIZE));

    return 0;
}
