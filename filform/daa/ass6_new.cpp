#include <bits/stdc++.h>
using namespace std;


// Partition function for deterministic quicksort
int deterministicPartition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in its correct position
    return i + 1;                // Return the partition index
}

// Deterministic QuickSort function
void deterministicQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);

        // Recursively sort the sub-arrays
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}





// Partition function for randomized quicksort
int randomizedPartition(int arr[], int low, int high) {
    // Generate a random index between low and high
    int randomPivotIndex = low + rand() % (high - low + 1);

    // Swap the randomly chosen pivot with the last element
    swap(arr[randomPivotIndex], arr[high]);

    // Proceed with the usual partitioning logic
    return deterministicPartition(arr, low, high);
}

// Randomized QuickSort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);

        // Recursively sort the sub-arrays
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main() {
    srand(time(0)); // Seed for the random number generator

    // Sample array
    int arr[] = {10, 7, 8, 9, 1, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Compare deterministic and randomized QuickSort

    deterministicQuickSort(arr,0,n-1);
    printArray(arr,n);

    randomizedQuickSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}
