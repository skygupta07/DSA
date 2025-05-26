// findKPairsWithSmallestSum.cpp
/*

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and 
one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 
Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3

Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
 
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]


Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence:

[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 10pow5
-10pow9 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 10pow4
k <= nums1.length * nums2.length

*/


// is the below code correct ?? think about it

#include <bits/stdc++.h>
using namespace std;


#define pp pair <int, pair <int, int> > 

class Solution {
public:
    vector <vector <int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Priority queue to store pairs with their sums
        priority_queue < pp, vector<pp>, greater<pp> > pq;

        // Insert the smallest pairs initially (first element from nums1 and each element from nums2)
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> result;

        // Extract the k smallest pairs
        while (!pq.empty() && k--) {
            auto p = pq.top();
            pq.pop();

            int i = p.second.first;
            int j = p.second.second;

            result.push_back({nums1[i], nums2[j]});

            // If there is any more elements in nums2 for the current nums1 element, add the next pair
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return result;
    }
};
