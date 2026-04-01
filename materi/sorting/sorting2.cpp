#include<iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

int main()
{
    int a=2, b=7, temp;
    cout << "Sebelum swap \na = " << a << "\tb = " << b << endl;
    temp = a; a = b; b = temp;
    cout << "Setelah swap \na = " << a << "\tb = " << b << endl;

    int arrB[] = {64, 34, 25};
    int sb = sizeof(arrB) / sizeof(arrB[0]);
    cout << "\nsb = " << sizeof(arrB) << " / " << sizeof(arrB[0]) << " = " << sb << endl;
    cout << "\nSebelum Bubble Sort\n";
    printArray(arrB, sb);
    bubbleSort(arrB, sb);           // ✅ panggil sort
    cout << "Setelah Bubble Sort\n";
    printArray(arrB, sb);

    int arrS[] = {64, 34, 25};
    int ss = sizeof(arrS) / sizeof(arrS[0]);
    cout << "\nss = " << sizeof(arrS) << " / " << sizeof(arrS[0]) << " = " << ss << endl; // ✅ ss
    cout << "\nSebelum Selection Sort\n";
    printArray(arrS, ss);
    selectionSort(arrS, ss);        // ✅ panggil sort
    cout << "Setelah Selection Sort\n";
    printArray(arrS, ss);

    return 0;
}

void selectionSort(int arr[], int n){
    int i, j, min_idx, temp;
    for(i=0; i<n-1; i++){           // ✅ i++
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){           // ✅ i<n-1
        for(j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){         // ✅ i<n
        cout << arr[i] << " ";
    }
    cout << endl;
}