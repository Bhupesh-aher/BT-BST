#include<bits/stdc++.h>
using namespace std;

// Same logic is used by me and babbar 
class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        double element = -1;
        if(n % 2 == 1) {
             element = arr[n/2];
        }
        else {
            element = (arr[n/2] + arr[n/2-1]) / 2.0;
        }
        return element;
    }
};

// TC - O(n ^2 log n) 
// SC - O(n) 







// here this is my code as we have class based structure of code 
// in babbar's code it is a function and data is given in form of array so the implemention is diff but logic stays same

class MedianFinder {
    public:
    // Max-heap for the left half
    std::priority_queue<int> left;
    
    // Min-heap for the right half
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    
    MedianFinder() {}
    
    void addNum(int num) {
        // Step 1: Add to max-heap
        left.push(num);
        
        // Step 2: Balance max and min heaps
        right.push(left.top());
        left.pop();
        
        // Step 3: Maintain size property
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();  // Odd number of elements
        } else {
            return (left.top() + right.top()) / 2.0;  // Even number of elements
        }
    }
};

// TC - O(n log n) 


// addNum() runs in O(log n) time.

// findMedian() runs in O(1) time.

// 🔧 How It Works:

// Max-heap (left): holds the smaller half of the numbers.

// Min-heap (right): holds the larger half of the numbers.

// The size of both heaps is balanced such that:

// left.size() >= right.size()

// The size difference is at most 1.

// The median is:

// The top of left if the total size is odd.

// The average of the tops of both heaps if even.


// babbar's code which we discuss in above codes comment

int signum(int a, int b){
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void callMedian(int element, priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right, int &median){
    switch (signum(left.size(), right.size())){
        case 0: if(element > median){
                    right.push(element);
                    median = right.top();
                }
                else {
                    left.push(element);
                    median = left.top();
                }
                break;
        case 1: if(element > median){
                    right.push(element);
                    median = (left.top() + right.top()) / 2;
                }
                else {
                    right.push(left.top());
                    left.pop();
                    left.push(element);
                    median = (left.top() + right.top()) / 2;
                }
                break;
        case -1: if(element > median){
                        left.push(right.top());
                        right.pop();
                        right.push(element);
                        median = (left.top() + right.top()) / 2;
                    }
                    else {
                        left.push(element);
                        median = (left.top() + right.top()) / 2;
                    }
                    break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int median = 0;

    for(int i = 0; i<n; i++){
        callMedian(arr[i], left, right, median);
        ans.push_back(median);
    }
    return ans;

}

// TC - O(n log n) 





