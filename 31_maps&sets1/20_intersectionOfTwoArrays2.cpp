// intersectionOfTwoArrays2.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. 
Intersection of two arrays is said to be elements that are common in both arrays. 
The intersection should not have duplicate elements and the result should contain items in any order.

Note: The driver code will sort the resulting array in increasing order before printing.

Examples:

Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
Output: [1, 3]
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence 
of common elements.


Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
Output: [1]

Explanation: 1 is the only common element present in both the arrays.


Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
Output: []

Explanation: No common element in both the arrays.


Constraints:
1 ≤ a.size(), b.size() ≤ 1e5
1 ≤ a[i], b[i] ≤ 1e5

*/


class Solution {
public:

    vector <int> intersect(vector <int> &nums1, vector <int> &nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;

        vector <int> result;
        
        while (i < nums1.size() && j < nums2.size()) {

            // jo chota usi ka pointer aage
            if (nums1[i] < nums2[j]) { 
                i++;
            } 

            else if (nums1[i] > nums2[j]) {
                j++;
            }

            // both elements are equal 
            else{   
                result.push_back(nums1[i]);

                i++;
                j++;
            }
        }

        return result;
    }

};