#include<bits/stdc++.h>
using namespace std;

long long minCost(vector<long long> &arr){
    priority_queue<long long, vector<long long>, greater<long>> pq;
    for(int i = 0; i<arr.size(); i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

// TC - O(n log n) 
// SC - O(n) 

int main(){

    vector<long long> arr = {4, 3, 2, 6};
    cout << "Minimum cost to connect the ropes is " << minCost(arr);
    
} 




