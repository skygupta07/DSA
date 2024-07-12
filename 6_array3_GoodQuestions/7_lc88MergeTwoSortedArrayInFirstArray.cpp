#include <iostream>
#include <vector>
using namespace std;
int main(){


} 


You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored
 inside the array nums1. To accommodate this, nums1 has a length of m + n, where the
  first m elements denote the elements that should be merged, and the last n elements
   are set to 0 and should be ignored. nums2 has a length of n.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


/* two pointer
We can start with two pointers i and j, initialized to m-1 and n-1, respectively.
 We will also have another pointer k initialized to m+n-1, which will be used to keep track of the position
in nums1 where we will be placing the larger element. Then we can start iterating from the end of the arrays
i and j, and compare the elements at these positions. We will place the larger element in nums1 at position k,
and decrement the corresponding pointer i or j accordingly. We will continue doing this until we have iterated 
through all the elements in nums2. If there are still elements left in nums1, we don't need to do anything 
because they are already in their correct place

*/