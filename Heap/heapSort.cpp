#include<bits/stdc++.h>
using namespace std;

// given an array in random order we need to return it in sorted order
// first we convert that array into max heap using heapify algorithm
// then we use heap sort() to sort the array by implementing the logic and with the help of hepify algorithm
// in short 
// 1. build (create) a heap from given input array using heapify algorithm
// 2. call hep sort () which has some logic and it takes help of hepify algo
// 3. and return the sorted array


// Max Heap
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

    // an array in random order
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Created a Max heap (we build max heap / heap creation) from input array
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }


    // given max heap, we need return a sorted array. for that we use heap sort
    heapSort(arr, n);

    for(int i = 1; i<=n; i++){
        cout << arr[i] << " ";
    }
    

 

} 



