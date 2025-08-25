#include<bits/stdc++.h>
using namespace std;


// Build Max Heap
void heapify(int arr[], int n, int i){

    int largest = i;

    // we followed 1 based indexing 
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if(leftChild < n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild < n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// TC - O(log N) Heapify Algorithm



// Build Min Heap
void heapify_minHeap(vector<int> &arr2, int n, int i){

    int smallest = i;

    // we followed 0 based indexing 
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && arr2[smallest] > arr2[leftChild]){
        smallest = leftChild;
    }
    if(rightChild < n && arr2[smallest] > arr2[rightChild]){
        smallest = rightChild;
    }

    if(smallest != i){
        swap(arr2[smallest], arr2[i]);
        heapify_minHeap(arr2, n, smallest);
    }
}

// TC - O(log N) Heapify Algorithm


int main(){

    // Max Heap

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the arr after Building Max Heap algorithm " << endl;
    for(int i = 1; i<=n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;


    // Min Heap

    vector<int> arr2 = {54, 53, 55, 52, 50};

    for(int i = arr2.size()/2-1; i>=0; i--){
        heapify_minHeap(arr2, arr2.size(), i);
    }

    cout << "Printing the arr after Building Min Heap algorithm " << endl;
    for(int i = 0; i<arr2.size(); i++){
        cout << arr2[i] << " ";
    }


 

} 



