#include<bits/stdc++.h>
using namespace std;

class heap{
public: 
    int arr[100];
    int size;

    heap(){
        size = 0;
    }

    void insert(int val){
        size ++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void print(){
        for(int i = 1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap(){
        if(size == 0) {
            cout << "Nothing to delete " << endl;
            return;
        }
        arr[1] = arr[size];     // step 1 -  putting last index val to first index val;
        size --;                // step 2 - remove last element

        // step 3 - take root node to it's correct position
        int i = 1;
        while(i < size){
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;

            if(leftChildIndex < size && arr[i] < arr[leftChildIndex]){
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }
            else if(rightChildIndex < size && arr[i] < arr[rightChildIndex]){
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else return;
        }
    }
};

// TC - O(log N) To insert and delete in heap


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
} 



