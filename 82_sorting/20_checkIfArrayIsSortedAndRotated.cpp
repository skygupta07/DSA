#include <bits/stdc++.h>
using namespace std;


/*

Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that 
B[i] == A[(i+x) % A.length] for every valid index i.
 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].


Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.


Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/


class Solution {
public:

    bool isSorted(vector <int> &nums){
        int n = nums.size();

        for (int i=1; i<n; i++){
            if (nums[i] < nums[i-1]) return false;
        }

        return true;
    }


    bool check(vector<int>& nums) {
        int n = nums.size();

        int pivotIdx = -1;
        
        for (int i=1; i<n; i++){
            if (nums[i] < nums[i-1]){
                pivotIdx = i;
                break;
            }
        }

        if (pivotIdx != -1){

            reverse(nums.begin(), nums.begin()+pivotIdx);
            reverse(nums.begin()+pivotIdx, nums.end());

            reverse(nums.begin(), nums.end());

            return isSorted(nums);
        }

        else return true;
    }
};

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Count the number of times nums[i] > nums[i+1]
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // The array can be rotated and sorted if this count is at most 1
        return count <= 1;
    }
};


class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) return true;  // Single element array is trivially sorted.

        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());

        // Concatenate the original array with itself
        vector<int> twiceNums(nums.begin(), nums.end());
        twiceNums.insert(twiceNums.end(), nums.begin(), nums.end());

        // Check if this sorted array v is found as a contiguous subarray in twiceNums

        for (int i = 0; i < nums.size(); i++) {
            bool found = true;
            
            for (int j = 0; j < nums.size(); j++) {
                if (twiceNums[i + j] != v[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }

        return false;
    }
};
