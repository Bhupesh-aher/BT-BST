#include<bits/stdc++.h>
using namespace std;

// Given an array find the kth largest sum of subarray
// arr[] = [2, 6, 4, 1], k = 3
// The different subarray sums we can get from the array are = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.

int getKthLargest(vector<int> &nums, int k){
    vector<int> sumofAllSubarray;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        int sum =0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            sumofAllSubarray.push_back(sum);
        }
    }
    sort(sumofAllSubarray.begin(), sumofAllSubarray.end());
    return sumofAllSubarray[sumofAllSubarray.size() - k];
}

// TC - O(N^2) + O(n log n) 
// SC -  O(N^2)



// we Previously solved the kth largest sum in array. same thing will do here.
// we want largest so will use min heap
// here there is subarray in Previously there was just an array


int getKthLargest(vector<int> &nums, int k){
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += nums[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();

}

// TC - O(N^2 log(k))
// SC - O(k)


int main(){
    

    vector<int> arr = {1, 2, 6, 4, 3};  // ans = 13
    int k = 3;
    cout << getKthLargest(arr, k);

} 




