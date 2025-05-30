#include <bits/stdc++.h>
using namespace std;

/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside 
the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 
nums2 has a length of n.


Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].


Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result 
can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

*/

// two Pointer and Using Third Vector
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m + n, 0);

        // Two pointers
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int k = 0; // Pointer for nums3

        // Merging the two arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums3[k++] = nums1[i++]; // Add nums1[i] to nums3 and increment both pointers
            } 
            else {
                nums3[k++] = nums2[j++]; // Add nums2[j] to nums3 and increment both pointers
            }
        }

        // If any elements left in nums1
        while (i < m) {
            nums3[k++] = nums1[i++]; // Add remaining elements of nums1
        }

        // If any elements left in nums2
        while (j < n) {
            nums3[k++] = nums2[j++]; // Add remaining elements of nums2
        }

        // Copy merged elements back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};



// two pointer inplace modification (ulti ungli se ghee)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0){ // chote wale pe constraint
            
            if (i >= 0 && nums1[i] > nums2[j]) {    // valid index check first, then jo jeeta 
            // uska hi contribution add and then peeche peeche chalte raho...
                nums1[k--] = nums1[i--];
            } 
            
            else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


/*
ulti ungli se ghee..
*/


