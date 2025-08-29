#include<bits/stdc++.h>
using namespace std;

// Given 2 arrays merge them and build max heap from it



// Build Max Heap from given input array
void heapify(vector<int> &arr, int n, int i){

    int largest = i;

    // we followed 0 based indexing 
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

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


int main(){
    
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    // ans -  12 10 9 2 5 7 6 after merging and converting into max heap
    

    // step 1: merge both arrays into 1 array
    vector<int> ans;
    for(auto it: a) ans.push_back(it);
    for(auto it: b)  ans.push_back(it);


    // step 2: build max heap using merge array - we build it using heapify algo (we seen it prevoisuly)
    int n = ans.size();
    for(int i = n/2-1; i>=0; i--){
        heapify(ans, n, i);
    }

    for(auto it: ans) cout << it << " ";

    // TC - O(N + M) + O(N) 
    // SC - O(N + M) + O(log n)


} 




