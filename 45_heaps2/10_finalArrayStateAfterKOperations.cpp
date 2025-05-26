#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. 

In each operation: Find the minimum value x in nums. 

If there are multiple occurrences of the minimum value, select the one that appears first.

Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.
 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]


Example 2:

Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5

*/

class Solution {
public:

    vector<int> getFinalState(vector<int>& nums, int k, int m) {

        // Corrected priority_queue declaration
        // element, index
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Fill the priority queue with elements and their indices
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});  // element, index
        }

        // Perform the operation k times
        while (!pq.empty() && k--) {
            pair <int, int> p = pq.top();  // Get the smallest element
            pq.pop();

            // Multiply the element by m and push it back with the same index
            pq.push({p.first * m, p.second});
        }

        // Prepare the final result array
        vector <int> ans(nums.size());

        // Fetch elements from the priority queue in the order of their original indices
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int idx = p.second;
            int el = p.first;

            ans[idx] = el;
        }

        return ans;
    }
};
