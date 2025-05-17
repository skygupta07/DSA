#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-2pow31 <= nums[i] <= 2pow31 - 1

*/


// brute force => gives tle..
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if (nums[i] > (long long) 2 * nums[j]) count++;
            }
        }

        return count;
    }
};


// optimised approach - using merge sort

class Solution {
private: 
    // Merge function: Sorting karte waqt reverse pairs count karte hain
    void merge(vector<int>& nums, int& reversePairsCount, int lo, int mid, int hi) {
        int j = mid + 1; // Right subarray ke starting index
        
        // Reverse pairs ko count karte hain - important loop ek element first part se aa rha h to dusra dusre part se..
        for (int i = lo; i <= mid; i++) {
            while (j <= hi && nums[i] > 2 * (long long)nums[j]) {
                // Agar nums[i] > 2 * nums[j], to ye reverse pair hai
                j++;
            }
            reversePairsCount += j - (mid + 1); // Valid pairs ka count add karte hain
        }
        
        // Merge karte hain sorted subarrays ko
        int size = hi - lo + 1; // Current subarray ka size
        vector<int> temp(size, 0); // Temporary array for merging

        int left = lo, right = mid + 1, k = 0;

        // Dono sorted arrays ko merge karte hain
        while (left <= mid && right <= hi) {
            if (nums[left] < nums[right]) {
                temp[k++] = nums[left++]; // Left array ka element add karo
            }
            else {
                temp[k++] = nums[right++]; // Right array ka element add karo
            }
        }

        // Agar left array ke elements bache hain
        while (left <= mid) {
            temp[k++] = nums[left++];
        }

        // Agar right array ke elements bache hain
        while (right <= hi) {
            temp[k++] = nums[right++];
        }

        // Temporary array se sorted elements original array mein copy karte hain
        int m = 0;

        for (int i = lo; i <= hi; i++) {
            nums[i] = temp[m++];
        }

    }

    // Merge sort function: Recursive sorting + reverse pairs counting
    void mergeSort(vector<int>& nums, int& reversePairsCount, int lo, int hi) {
        if (lo >= hi) {
            return; // Base case: Single element ya empty subarray
        }

        int mid = lo + (hi - lo)/2; 

        mergeSort(nums, reversePairsCount, lo, mid); // Left half sort karo
        mergeSort(nums, reversePairsCount, mid + 1, hi); // Right half sort karo

        merge(nums, reversePairsCount, lo, mid, hi); // Merge and count reverse pairs
    }

public:
    // Main function to find reverse pairs
    int reversePairs(vector<int>& nums) {

        int reversePairsCount = 0; 

        mergeSort(nums, reversePairsCount, 0, nums.size() - 1); 

        return reversePairsCount; 
    }
};
