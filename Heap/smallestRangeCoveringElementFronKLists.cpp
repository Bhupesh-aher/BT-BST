#include<bits/stdc++.h>
using namespace std;


vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();                // Number of lists
    vector<int> indices(k, 0);          // Pointer for each list
    int minRange = INT_MAX;             // Track the smallest range
    int start = -1, end = -1;           // Final answer [start, end]

    while (true) {
        int currentMin = INT_MAX;
        int currentMax = INT_MIN;
        int minListIndex = -1;

        // Get current values from each list using pointers
        for (int i = 0; i < k; ++i) {
            // If we've reached the end of any list, stop the loop
            if (indices[i] >= nums[i].size()) {
                return {start, end};
            }

            int val = nums[i][indices[i]];
            
            // Track min and max
            if (val < currentMin) {
                currentMin = val;
                minListIndex = i; // Remember which list had the min
            }
            if (val > currentMax) {
                currentMax = val;
            }
        }

        // Update the best range if found smaller
        if ((currentMax - currentMin) < minRange) {
            minRange = currentMax - currentMin;
            start = currentMin;
            end = currentMax;
        }

        // Move forward in the list which had the minimum value
        indices[minListIndex]++;
    }
}

// TC - O(n * k^2)
// SC - O(k)




// below 2 codes logic is exaclty same just diff style of code is used

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

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();                
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i = 0; i<k; i++){
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->j + 1  < nums[temp->i].size()){
            maxi = max(maxi, nums[temp->i][temp->j + 1]);
            minHeap.push(new node(nums[temp->i][temp->j + 1], temp->i, temp->j + 1));
        }
        else{
            break;
        }
    }
    return {start, end};
}







// chat gpt code same logic as above just code style is different
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // Min-heap: stores (value, listIndex, indexInList)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        int maxVal = INT_MIN; // Track the current maximum value
        int rangeStart = 0, rangeEnd = INT_MAX;

        // Step 1: Insert first element from each list into the heap
        for (int i = 0; i < k; ++i) {
            int val = nums[i][0];
            minHeap.push({val, i, 0});
            maxVal = max(maxVal, val);
        }

        // Step 2: Process the heap
        while (minHeap.size() == k) {
           auto t = minHeap.top();
            minHeap.pop();
            int minVal = get<0>(t);
            int listIdx = get<1>(t);
            int idxInList = get<2>(t);

            // Update range if smaller
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Move to next element in the list
            if (idxInList + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][idxInList + 1];
                minHeap.push({nextVal, listIdx, idxInList + 1});
                maxVal = max(maxVal, nextVal); // Update max
            } else {
                // One list is exhausted, can't include all k lists anymore
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};



// TC - O(N log k)
// SC - O(k) 


int main() {
    vector<vector<int>> nums = {
        {1, 10, 11},
        {2, 3, 20},
        {5, 6, 12}
    };

    vector<int> result = smallestRange(nums);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}




//  {4, 10, 15, 24, 26},
//  {0, 9, 12, 20},
//  {5, 18, 22, 30}

// Smallest range: [20, 24]