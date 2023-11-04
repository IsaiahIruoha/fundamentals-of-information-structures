#include <stdio.h>

int array_average(const int *array, size_t count) {
    // Return the average of the 'count' elements of 'array'
    int sum = 0;
    // Loop through the array and add each element to the sum
    for (int i = 0; i < count; i++) {
        sum += array[i];
    }
    return sum / count;
}

int max_element(const int *array, size_t count) {
    // Return the largest element in 'array'
    int max = array[0];
    // Loop through the array and compare each element to the max
    for (int i = 0; i < count; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main() { 
    // Prints the average of the array and the max element of the array
    // Hard-coded array with integers
    int myArray[] = {1, 2, 3, 4, 5};

    // Get the size of the array
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    // Print the results of the average and max functions
    printf("Average of the array: %d\n", array_average(myArray, arraySize));
    printf("The max element in the array is: %d\n", max_element(myArray, arraySize));
}
