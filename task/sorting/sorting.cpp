#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);

int main() {
    int arr[] = {29, 9, 20, 5, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sebelum Bubble Sort:\n";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "\nSetelah Bubble Sort:\n";
    printArray(arr, n);

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) { // asc
                //
                temp = arr[j];
                arr[j] = arr[j+1];    
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}