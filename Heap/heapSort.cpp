#include<bits/stdc++.h>
using namespace std;



void heapify(int arr[], int n, int i){

    int largest = i;

    // we followed 1 based indexing 
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if(leftChild <= n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild <= n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        // step1

        swap(arr[size], arr[1]);   
        size --;

        // step 2
        heapify(arr, size, 1);
    }
}

// TC - O(N log N) Heap Sort




int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }


    heapSort(arr, n);

    for(int i = 1; i<=n; i++){
        cout << arr[i] << " ";
    }
    

 

} 



