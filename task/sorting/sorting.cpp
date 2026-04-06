#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);


int main() {
    // Bubble Sort
    int arrB[] = {29, 9, 20, 5, 64};
    int sb = sizeof(arrB) / sizeof(arrB[0]);
    cout << "Sebelum Bubble Sort:\n";
    printArray(arrB, sb);
    bubbleSort(arrB, sb);
    cout << "Setelah Bubble Sort:\n";
    printArray(arrB, sb);

    // Selection Sort 
    int arrS[] = {29, 9, 20, 5, 64};
    int ss = sizeof(arrS) / sizeof(arrS[0]);
    cout << "\nSebelum Selection Sort\n";
    printArray(arrS, ss);
    selectionSort(arrS, ss);
    cout << "Setelah Selection Sort\n";
    printArray(arrS, ss);


    // Insertion Sort 
    int arrI[] = {29, 9, 20, 5, 64};  
    int n = 5;                          
    cout << "\nSebelum Insertion Sort\n";
    printArray(arrI, n);
    insertionSort(arrI, n);
    cout << "Setelah Insertion Sort\n";
    printArray(arrI, n);


    return 0;
}

void insertionSort(int arr[], int n){  
    int i, key, j;
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            printArray(arr, n);     
        }
        arr[j+1] = key;
        printArray(arr, n);        
    }
}

void selectionSort(int arr[], int n){
    int i, j, min_idx, temp;
    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        printArray(arr, n);
    }
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