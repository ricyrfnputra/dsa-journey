/*
    Ricy Rifani Putra - A11.20205.16464
    Selasa, 31 Maret 2026 - H.4.4
    Sourcing Searching

*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

int main()
{   
    int a=2, b=7, temp;
    cout << "Sebelum swap \na = " << a << "\tb = " << b << endl;
    temp = a;
    a = b;
    b = temp;

    cout << "Setelah swap \na = " << a << "\tb = " << b << endl;


    int arrB[] = {64, 34, 25};
    int sb = sizeof(arrB) / sizeof(arrB[0]); // 3
    cout << "\nsb = " << sizeof(arrB) << " / " << sizeof (arrB[0]) << " = " << sb << endl;
    cout << "\n sebelum Bubble Sort \n";
    printArray(arrB, sb);   // var. aktual
    


    int arrS[] = {64, 34, 25};
    int ss = sizeof(arrS) / sizeof(arrS[0]); // 3
    cout << "\nsb = " << sizeof(arrS) << " / " << sizeof (arrS[0]) << " = " << sb << endl;
    cout << "\n setelah Bubble Sort \n";
    printArray(arrS, ss);   // var. aktual
    
    return 0;
}
// bawah INT MAIN

void selectionSort(int arr[], int n){
    int i, j, min_idx, temp;
    for(i=0; i<n-1; temp){
        min_idx = i;
        for(j=i+1; j<n; j++){   // loop u/ mencari index nilai terkecil
            if(arr[j] < arr[min_idx])
                min_idx = j; // aksi if 1 saja boleh tanpa { }
        }
        // keluar dari loop j, swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1-i; i++){
        for(j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){ // asc
                //
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            printArray(arr, n);
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<0; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

