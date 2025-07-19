// findFirstAndLastPositionOfElementInSortedArray.cpp

/*

Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]


Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10pow5
-10pow9 <= nums[i] <= 10pow9

nums is a non-decreasing array.
-10pow9 <= target <= 10pow9

*/



#include <bits/stdc++.h>
using namespace std;

 // O(n) - linear solution
class Solution {
public:

    vector <int> searchRange(vector <int> &nums, int target){
        int n = nums.size();

        int startingPosition = -1, endingPosition = -1;
 
        // front se loop chalaya to find first occurence
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;  // jaise hi mil gya uske baad chal chal bhai chal nikal le ha..
            }
        }

        // back se loop chalaya to find last occurence
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }

        return {startingPosition, endingPosition};
    }
};


/*

    Time Complexity : O(N), because in the worst case we traverse the <= N element. 
    Where N is the size of the Array(nums).
                    
    Space Complexity : O(1), the space complexity is constant.

    Solved using Linear Search.

*/


class Solution {
public:

    // to find first position of element
    vector <int> searchRange(vector <int> &nums, int target){
        int start = -1, end = -1;

        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi){

            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] == target){

                if (mid-1 >=0 && nums[mid - 1] != target){
                    start = mid; // storing index
                    break;
                }
                else{
                    hi = mid - 1;  // girl searching for better option always
                }
            }

            else if (nums[mid] < target) lo = mid+1;
            else hi = mid - 1;
        }

        // reset lo and hi again to find last position of element
        lo = 0;
        hi = nums.size() - 1;
        
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] == target){
                if (mid+1 <= hi && nums[mid + 1] != target){
                    end = mid;
                    break;
                }
                else{
                    lo = mid + 1;   // girl searching for better option
                }
            }
            else if (nums[mid] < target) lo = mid + 1;
            
            else hi = mid - 1;
        }

        return {start,end};
    }
};

/*
    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(1), since we stored only some constant number of elements, the space complexity is
    constant.

    Solved using Binary Search.
*/






