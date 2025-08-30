#include<bits/stdc++.h>
using namespace std;

// my code 
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int i = 0; i<nums.size(); i++){
        pq.push(nums[i]);
    }
    while(k > 0){
        k --;
        if(k == 0) return pq.top();
        else pq.pop();
    }
    return -1;
}


// TC - O(n log n) + O(k)
// SC - O(n)


// babbar's code
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<k; i++){
        pq.push(nums[i]);
    }
    for(int i = k; i<nums.size(); i++){
        if(nums[i] > pq.top()){
            pq.pop();
            pq.push(nums[i]); 
        }
    }
    return pq.top();
}

// TC - O(k log n) 
// SC - O(k) 

// btoh approaches are correct just intution is different



int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k);

  
} 




