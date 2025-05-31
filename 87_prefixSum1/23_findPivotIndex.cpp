#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index
is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0
because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3

Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

*/


class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();

        vector <int> prefSum(n, 0); // prefix sum except self
        vector <int> suffSum(n, 0); // suffix sum except self

        for (int i=1; i<n; i++) prefSum[i] = arr[i-1] + prefSum[i-1];

        for (int j=n-2; j>=0; j--) suffSum[j] = arr[j+1] + suffSum[j+1];


        for (int i=0; i<n; i++){
            if (prefSum[i] == suffSum[i]) return i;
        }

        return -1;

    }
};


/*
prefSum (except self)
suffSum (except self)

iterate and see if at any idx prefSum[i] == suffSum[i] return i;

return -1;
*/