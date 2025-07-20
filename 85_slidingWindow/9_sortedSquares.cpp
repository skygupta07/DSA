// squaresOfASortedArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.


Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].


Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 1e4
-1e4 <= nums[i] <= 1e4
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, 
could you find an O(n) solution using a different approach?

*/

// brute force
class Solution {
public:

        vector <int> sortedSquares(vector <int> &nums){
            int n = nums.size();
    
            for (int i=0; i<n; i++) nums[i] *= nums[i];
        
            sort(nums.begin(), nums.end());

            return nums;
        }
};


class Solution {
public:

        vector <int> sortedSquares(vector <int> &arr){

            int n = arr.size();  // Get the size of the input array
            
            int left = 0;        // Pointer to the leftmost element
            int right = n - 1;   // Pointer to the rightmost element
            
            vector <int> ans(n);  // Result vector to store squared values in sorted order
    
            int val; // Variable to hold the current value being squared
            
            for (int i = n - 1; i >= 0; i--) { // Fill the answer array from the largest index
                
                // Compare absolute values of elements at left and right pointers
                if (abs(arr[left]) < abs(arr[right])) {
                    val = arr[right]; // Choose the larger absolute value from the right
                    right--;          // Move the right pointer left
                } 
                
                else {
                    val = arr[left];  // Choose the larger absolute value from the left
                    left++;           // Move the left pointer right
                }
    
                ans[i] = (val * val); // Square the selected value and store it at index 'i'
            }
            
            return ans; // Return the sorted squared array
        }
    };
    

/*
when to use two pointer approach? => 
case 1 : use when you can see that two points are representing some information 
about some changes there like (both inc. inc). (both decs. decs.) 

(also somewhat similar intuition is built in case of binary search but remember
 that in case of binary search you have
increasing decreasing values and you need the middle one from them...)


case 2: when there are 2 or 3 kind of strings in the array/string... 

I will compare the absolute value and put the corresponding square values there...

*/
