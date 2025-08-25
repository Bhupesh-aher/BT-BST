#include<bits/stdc++.h>
using namespace std;





int main(){

    // Max Heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    
    cout << "Element at Top " << pq.top() << endl;
    pq.pop();
    cout << "Element at Top " << pq.top() << endl;
    cout << "Size of priority_queue is " << pq.size() << endl;

    if(!pq.empty()) cout << "priority_queue is not empty" << endl;
    else cout << "priority_queue is empty" << endl;

    cout << endl;


    // Min Heap

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at Top Min Heap is  " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at Top of Min Heap is " << minheap.top() << endl;
    cout << "Size of priority_queue is " << minheap.size() << endl;

    if(!minheap.empty()) cout << "Min Heap is not empty" << endl;
    else cout << "Min Heap is empty" << endl;

} 




