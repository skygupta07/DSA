#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, move all 0's to the end of it while maintaining the relative order 
of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 
*/

class Solution {
public:
    void moveZeroes(vector<int>& arr){
        int n = arr.size();
        int zcount = 0;

        for (int i=0; i<n; i++){
            if (arr[i] == 0) zcount++;
        }
        
        for (int i=0; i<zcount; i++){
            for (int j=0; j<n-1; j++){
                if ( arr[j] == 0 && arr[j+1]!=0){
                    swap(arr[j] , arr[j+1]);
                }
            }
        }
    }
};


/*

Count zeros (zcount) → How many zeros are in the array.
For each zero (run zcount times):
Traverse the array from left to right.
If current element is 0 and next one is not, swap them.
This pushes zeros to the right gradually (like bubbles in bubble sort).

*/


class Solution {
public:
    void moveZeroes(vector<int>& arr){
        int n = arr.size();
        int j = -1;  // j will store index of first 0

        // Step 1: Find the index of first 0
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                j = i;  // first zero mil gaya, store index
                break;
            }
        }

        // Agar koi zero mila hi nahi, to array already sorted hai → return
        if (j == -1) return;

        // Step 2: Traverse from j+1 to end
        for (int i = j + 1; i < n; i++) {
            // Agar non-zero mila to usse j wale 0 ke sath swap karo
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;  // ab agla zero ka place j+1 hoga
            }
        }

        return;
    }
};


// find the first zero element then keep a pointer  j on it