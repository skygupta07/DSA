// peakElement

/*

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. 
In other words, an element is always considered to be strictly greater than a neighbor 
that is outside the array.

You must write an algorithm that runs in O(log n) time.

 
Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.


Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, 
or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-2e31 <= nums[i] <= 2e31 - 1
nums[i] != nums[i + 1] for all valid i.

*/



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        for (int i=0; i<n; i++){
            if (i == 0){
                if (nums[0] > nums[1]) return 0;
            }

            else if (i == n-1){
                if (nums[n-1] > nums[n-2]) return n-1;
            }

            else{
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
            }
        }

        return -1;

    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if (nums[i] > nums[i+1]) return i;
        }

        return n-1;
    }
};


/*

aur ye bhi confirm h ki peak element to milna hi hai...

koi bhi peak element return karna h to phir simply iterate karte huye chalo ....
kisi bhi point pe next element greater mil jaata hai... to phir return that index only...

*/


// remembering algo...
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();

        int lo = 0;
        int hi = n - 1;

        // Binary Search to find a peak
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // If mid is less than its next element,
            // the peak lies in the right half
            if (arr[mid] < arr[mid + 1]) {
                lo = mid + 1;
            }
            // Else, peak lies in the left half (including mid)
            else {
                hi = mid;
            }
        }

        // lo == hi → index of a peak element
        return lo;
    }
};



class Solution {
public:

    int recursiveBinarySearch(vector <int> &nums, int lo, int hi){
        if (lo == hi) return lo;
        
        int mid = lo + (hi - lo)/2;
        if (nums[mid] > nums[mid + 1]) return recursiveBinarySearch(nums, lo, mid);
        else return recursiveBinarySearch(nums, mid+1, hi);
    }

    int findPeakElement(vector<int>& nums) {
        // lo = 0, hi = n -1 
        return recursiveBinarySearch(nums, 0, nums.size() - 1);
    }
};


/*
recursive binary search 

if nums[mid] > nums[mid+1] lo se mid
else mid + 1 se hi tak
*/