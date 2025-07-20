// nextPermutation.cpp // asked by bineet

#include <bits/stdc++.h>
using namespace std;

/*

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: 
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation 
of its integer. 

More formally, if all the permutations of the array are sorted in one container 
according to their lexicographical order, then the next permutation of that array is the permutation 
that follows {follows matlab jo uske just baad aaye...} it in the sorted container. 

If such arrangement is not possible, 
the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] 
does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.


Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]


Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]


Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/


class Solution {
public:

    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int idx = -1; // 🔴 yeh index hume pivot index ke liye chahiye

        // ✅ Step 1: Find the pivot index (from right), jaha nums[i] < nums[i+1]
        // Yeh woh point hai jaha increasing order break hoti hai from the end

        for (int i = n - 2; i >= 0; i--) {
            // 🧠 We are finding first decreasing element from right side
            // i.e., nums[i] < nums[i+1] => this index is where we can make change
            if (nums[i] < nums[i + 1]) {
                idx = i;  // ✅ Pivot index found
                break;
            }
        }

        // ⚠️ If no pivot is found => array is sorted in descending order
        // => This is the highest permutation possible
        // So, just return the lowest permutation (ascending)
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // ✅ Step 2: Reverse the suffix (elements after idx)
        // Because after idx, array is in decreasing order
        // Reversing it will give us the lowest permutation of that part
        reverse(nums.begin() + idx + 1, nums.end());

        // ✅ Step 3: Find the element just greater than nums[idx]
        // Important: After reversing, the smallest larger element will be found early
        int j = -1;

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                j = i;
                break; // 🛑 First element just greater than pivot is our target
            }
        }

        // ✅ Step 4: Swap nums[idx] and nums[j]
        // This makes sure we are moving to the next higher permutation
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;

        return;
    }
    
};


/*

find all permuations then arrange in asc order
then return the next index of matching original array index

*/