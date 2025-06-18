// findAllDuplicatesInAnArray.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, 
excluding the space needed to store the output.


Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:

Input: nums = [1,1,2]
Output: [1]

Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length

1 <= n <= 1e5
1 <= nums[i] <= n

Each element in nums appears once or twice.

*/



// unordered_map 
class Solution {
public:

    vector <int> findDuplicates(vector <int> &nums) {
        vector <int> ans;
        unordered_map <int,int> mp;

        for (auto el: nums){
            mp[el]++;
        }

        for (auto el: mp){
            if (el.second == 2) ans.push_back(el.first);
        }

        return ans;
    }
};


// sort and then check adjacent elements

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;

        sort(nums.begin() , nums.end());

        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] == nums[i+1]) ans.push_back(nums[i]);
        }

        return ans;
    }
};

// brute force -> unordered map
// O(n^2) solution -> gives tle on 25th testcase.....even the break condition couldn't help to pass the 28th testcase
// sorting -> then check if adjacent elements are same then push them into ans vector...

// 1 2 2 3 3 4 7 8 



// brute force -> unordered map
// O(n^2) solution -> gives tle on 25th testcase.....even the break condition couldn't help to pass the 28th testcase
// 

// 1 2 2 3 3 4 7 8 


class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; // ✅ Final answer list for duplicates

        // ✅ Step 1: Traverse through each element
        for (int i = 0; i < nums.size(); i++) {

            // ➤ abs(nums[i]) ensures we get the original value even if it’s already negative
            int idx = abs(nums[i]) - 1; // ➤ Convert the value to index (0-based)

            // 🔁 Step 2: Negate the value at that index
            nums[idx] *= -1;

            // ➤ Step 3: Now if value at that index becomes **positive again**, it means:
            //    - It was already visited once (i.e., previously made negative)
            //    - Multiplying again (due to second encounter) made it positive again
            //    🔥 That means it's a **duplicate**

            if (nums[idx] > 0) {
                ans.push_back(idx + 1); // ➤ Convert index back to number and store
            }
            
        }

        // ✅ Step 4: Return the collected duplicates
        return ans;
    }
};


/*

optimised solution 
1. scan every element in array.

2. negate the value at index of (absolute value of scanned element - 1)

3. now check if the value which you negate -> 
if it is negative means you have encountered its first time ...

leave it .. but if it is positive => that it is a duplicate element....

*/