// findMinimumInRotatedSortedArray


/*

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
[a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.


Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.


Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.


Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

*/


#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


// inbuilt fn
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};


// O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i=0; i<nums.size(); i++) mini = min(mini, nums[i]);
        return mini;
    }
};


// O(logn)
class Solution {
public:

        int findMin(vector <int> &nums) {
            int n = nums.size();

            int lo = 0;
            int hi = n - 1;
    
            // Jab tak low aur high equal nahi ho jaate, tab tak loop chalega
            while (lo < hi) {
                // Yeh mid nikalne ka tareeka hai taaki overflow na ho
                int mid = lo + (hi - lo) / 2;
    
                // Agar mid element chhota hai high wale element se,
                // iska matlab minimum element mid ke left mein ho sakta hai ya mid hi ho sakta hai.
                // Isliye hum high ko mid pe le aate hain
                if (nums[mid] < nums[hi]) hi = mid;
    
                // Agar mid element bada ya barabar hai high se,
                // iska matlab minimum element mid ke right mein hoga
                // isliye low ko mid + 1 kar dete hain
                else lo = mid + 1;
            }
    
            // Jab loop khatam hota hai, low aur high same index pe hote hain,
            // jo ki minimum element ka index hota hai
            return nums[lo]; // ya nums[hi], dono same hain
        }
    };
    
