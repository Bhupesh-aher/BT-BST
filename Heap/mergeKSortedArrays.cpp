#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k){
    vector<int> mergedArrays;

    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j<arr[i].size(); j++){
            mergedArrays.push_back(arr[i][j]);
        }
    }
    return mergedArrays;
}

// TC - O(n * k) + O(n*k log n*k) 
// SC - O(n * k) 



// first we will take 1st element from all the arrays and put it in min heap
// then which ever is smaller will put it in merged array and will move to next elemnet of the same array from which we take element to push in min heap
// now to track from which arr i push element in min heap
// i need to track it. To track it we will create or own datatype (just like we do  in case of trees and linked list)
// and then in min heap instaed of greater we will write comnparetor for it
// will do this thing till min heap size () > 0



class node {
    public:
    int data;
    int i; 
    int j;

    node(int val, int row, int col){
        data = val;
        i = row;
        j = col;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k){
    priority_queue<node*, vector<node*>, compare> pq;

    // step 1: put the 1st element from all arrays
    for(int i = 0; i<k; i++){
        node* temp = new node(arr[i][0], i, 0);
        pq.push(temp);
    } 

    vector<int> ans;

    // step2:
    while(pq.size() > 0){
        node* temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();
        int row = temp->i;
        int col = temp->j;

        if(col + 1 < arr[row].size()){
            node* next = new node(arr[row][col + 1], row, col + 1);
            pq.push(next);
        }
    } 
    return ans;
}


// TC - O(k log k) + O(n log k) = O(n log k)
// SC - O(n + k)






int main(){
    
    vector<vector<int>> arr= {{1, 2, 3, 4},
                            {2, 2, 3, 4},
                            {5, 5, 6, 6},
                            {7, 8, 9, 9}};
    int k = 4;


    vector<int> ans = mergeKSortedArrays(arr, k);
    sort(ans.begin(), ans.end());
    for(auto it : ans) cout << it << " ";

} 




