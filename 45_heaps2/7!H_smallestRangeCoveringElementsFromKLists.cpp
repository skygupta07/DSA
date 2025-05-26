#include <bits/stdc++.h>
using namespace std;

/*

You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] 

if b - a < d - c or a < c if (b - a) == (d - c).


Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]

Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].


Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.

*/

class Solution {
public:
    vector <int> smallestRange(vector<vector<int>>& nums) {

        // Min-Heap: stores (value, list index, element index)
        priority_queue<vector<int>, vector <vector<int>>, greater<vector<int>>> minHeap;

        int curMax = numeric_limits<int>::min(); // or INT_MIN

        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        // Track the smallest range
        vector <int> smallRange = {0, numeric_limits<int>::max()};

        while (!minHeap.empty()) {

            // Get the minimum element from the heap
            vector <int> curr = minHeap.top();
            minHeap.pop();

            int curMin = curr[0], listIdx = curr[1], elemIdx = curr[2];

            // Update the smallest range if a better one is found
            if ((curMax - curMin < smallRange[1] - smallRange[0]) ||
                (curMax - curMin == smallRange[1] - smallRange[0] && curMin < smallRange[0])) {
                
                smallRange[0] = curMin;
                smallRange[1] = curMax;
                
            }

            // Move to the next element in the same list
            if (elemIdx + 1 < nums[listIdx].size()) {

                int nextVal = nums[listIdx][elemIdx + 1];

                minHeap.push({nextVal, listIdx, elemIdx + 1});
                curMax = max(curMax, nextVal);
            } 
            
            else {
                // If any list is exhausted, stop
                break;
            }
        }
        
        return smallRange;
    }
};



/*

merge k sorted list lagaya.. and now ek sorted array mil chuki hai.. 
now sliding window lagega... starting from window size = 2 se leke 
min(all the possible lengths of linked lists)

first check if this range is valid or not ? 
    i.e. whether it includes atleast a single element from all the lists or not?

*/