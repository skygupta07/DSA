/*
You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 
Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/


#include <bits/stdc++.h>
using namespace std;


void slideMax(int arr[], int n, vector <int> &v, int k){ // k=windowSize
                                                        // n = size of Array
    int i = 0;
    int j = i+k-1;
    
    while(j<=n-1){
        int max = arr[i];
        for (int idx=i; idx<=j; idx++){  // idx is pointer to travel over sliding window
            if (arr[idx]>max){
                max = arr[idx];
            }

        }
        v.push_back(max);
        i++;
        j++;
    }

}


// using priority queue
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            priority_queue <pair <int,int> > pq;  // (nums[i], i)   
    
            vector <int> ans(n - k + 1);    // when a window of size k slides over array of size k , then n - k + 1 different windows are possible...
    
            // push very first window elements into pq.
            for (int i=0; i<k; i++) pq.push({nums[i], i});  // yaha less than k tak 
    
            ans[0] = pq.top().first;    //very first max element.
    
            // ab start hi k se hoga loop for the next windows...
            for (int i=k; i<n; i++){
                // pop up the element not mean for the current window... (wo left wala element remove kar dega....)
                while (!pq.empty() && pq.top().second <= (i-k)) pq.pop();
    
                // in general push element and its index..
                pq.push({nums[i], i});
    
                // ans mai to i - k + 1 karke hi daalna padega.. as i index se to array par traverse kar rahe h and beech beech mai element leave bhi to karne h ... max lena h na bas kewal...
                ans[i - k + 1] = pq.top().first;
            }   
    
    
    
            return ans;
        }
    };


    // using array
    class Solution {
        public:
            vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                int n = nums.size(); // Total number of elements in the input array
        
                vector<int> maxIdx; // Deque-like vector to store indices of potential maximum elements
                vector<int> ans(n - k + 1); // Result vector to store the maximum of each sliding window
        
                int left = 0; // Pointer to track the leftmost valid index in the deque
                
                // Traverse the array
                for (int i = 0; i < n; i++) {
                    // Maintain the deque to only store indices of elements in decreasing order
                    // If the current element is greater than or equal to the last indexed element in deque,
                    // pop the indices from the back since they can no longer be maximum.
                    while (maxIdx.size() > left && nums[i] >= nums[maxIdx.back()]) {
                        maxIdx.pop_back();
                    }
        
                    // Add the current element's index to the deque
                    maxIdx.push_back(i);
        
                    // If the leftmost index in the deque is out of the current sliding window range, increment `left`
                    if (maxIdx[left] == i - k) {
                        left++;
                    }
        
                    // Once the window reaches size `k`, start recording the maximums
                    // The maximum of the current window is the value at the index `maxIdx[left]`
                    if (i >= k - 1) {
                        ans[i - k + 1] = nums[maxIdx[left]];
                    }
                }
        
                // Return the resulting array containing the maximums of all sliding windows
                return ans;
            }
        };






















// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// well done Akash...Hard Question of Leetcode done in single run ...WOW!!!

// but time limit exceed in hard questions due to brute force implementation

//better option will be to use next Greater Element concept here
/*

create a array and put index of next greater element in that array
taken a window see if the nge(next greater element)which is present in the window itself
could replace the current element... repeat the replacing nge step until you reach the
end of array...

*/