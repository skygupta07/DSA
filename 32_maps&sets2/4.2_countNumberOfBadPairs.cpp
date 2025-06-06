// countNumberOfBadPairs.cpp

/*

You are given a 0-indexed integer array nums. 
A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.


Example 1:

Input: nums = [4,1,3,3]
Output: 5

Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.


Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
 
        long long totalPairs = (1LL * n * (n - 1)) / 2; // nc2 pairs possible
        long long goodPairs = 0;
        
        unordered_map <int, int> mp; // Stores frequency of (nums[i] - i)

        for (int i = 0; i < n; i++) {
            goodPairs += mp[nums[i] - i]; // Count pairs where nums[j] - j == nums[i] - i
            
            
            mp[nums[i] - i]++; // Update frequency baad mai...
        }

        return totalPairs - goodPairs;
    }
};
