// minimumDifferenceBetweenLargestAndSmallestValueBetweeenThreeMoves.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums 
after performing at most three moves.

 
Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.

In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.


Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.


Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 

Constraints:

1 <= nums.length <= 10pow5
-10pow9 <= nums[i] <= 10pow9

*/
class Solution {
public:

    // ✅ Helper to calculate min diff after removing any 3 elements from either side
    int computeMinDifference(vector<int>& nums) {
        int n = nums.size();
        
        // Sort karne ke baad 4 possible ways honge 3 elements remove karne ke:
        // 1. Remove last 3 largest → max = nums[n-4], min = nums[0]
        // 2. Remove 2 largest, 1 smallest → max = nums[n-3], min = nums[1]
        // 3. Remove 1 largest, 2 smallest → max = nums[n-2], min = nums[2]
        // 4. Remove 3 smallest → max = nums[n-1], min = nums[3]

        return min({
            nums[n - 1] - nums[3],    // Case 1
            nums[n - 2] - nums[2],    // Case 2
            nums[n - 3] - nums[1],    // Case 3
            nums[n - 4] - nums[0]     // Case 4
        });
    }

    // ✅ Maintain only top 4 max and min values using heaps
    int computeUsingHeaps(vector<int> nums) {
        priority_queue<int> maxHeap;  // Keeps 4 smallest values (min heap behavior via max-heap)
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Keeps 4 largest values

        // Traverse array and maintain top 4 smallest and largest
        for (int num : nums) {
            maxHeap.push(num);  // for smallest 4
            if (maxHeap.size() > 4) maxHeap.pop();

            minHeap.push(num);  // for largest 4
            if (minHeap.size() > 4) minHeap.pop();
        }

        // Replace values at start and end to simulate removing elements
        int l = 3, r = nums.size() - 4;

        while (!maxHeap.empty()) {
            nums[l--] = maxHeap.top();  // Place smallest 4 at start
            maxHeap.pop();

            nums[r++] = minHeap.top();  // Place largest 4 at end
            minHeap.pop();
        }

        sort(nums.begin(), nums.end());  // Sort after placing min/max elements correctly

        return computeMinDifference(nums);
    }

    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;  // Can remove all elements, diff is 0

        // Approach using sorting and top elements via heaps
        return computeUsingHeaps(nums);
    }
};



// ------------------m2-----



class Solution {
public:

    int minDiff(vector <int> nums){
        int n = nums.size();
        return min({nums[n-1] - nums[3] , nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
    }


    int minDiffViaPq(vector <int> nums){
        priority_queue <int> mxheap;    //maxheap
        priority_queue < int, vector <int> , greater <int> > mnheap;

        for (auto el : nums){
            mxheap.push(el);
            mnheap.push(el);

            if (mxheap.size() > 4) mxheap.pop();
            if (mnheap.size() > 4) mnheap.pop();
        }

        int l = 3 , r = nums.size() - 4;

        while (!mxheap.empty()){
            nums[l--] = mxheap.top();
            mxheap.pop();

            nums[r++] = mnheap.top();
            mnheap.pop();
        }

        return minDiff(nums);
    }



    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4 ) return 0;
        return minDiffViaPq(nums);
    }
};