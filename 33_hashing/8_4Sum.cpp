// 4Sum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.

nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:

1 <= nums.length <= 200
-10pow9 <= nums[i] <= 10pow9
-10pow9 <= target <= 10pow9

*/


/*
1. sort -> 3 pointer + Binary Search

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n = nums.size();

        vector <vector <int>> res;
        if (nums.empty()) return res;
 
        sort(nums.begin() , nums.end());

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){

                long long int target_2 = 1LL*target - 1LL*nums[i]  -  1LL*nums[j];

                int front = j+1;
                int back = n-1;

                while ( front < back ){
                    int two_sum = nums[front] + nums[back];

                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;

                    else{   // target_2 ke liye two_sum found
                        vector <int> quadruplet(4,0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];

                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];

                        res.push_back(quadruplet);

                        // jumping over the duplicates of number 3
                        while (front < back && nums[front] == quadruplet[2]) front++;

                        // jumping over the duplicates of number 4
                        while (front < back && nums[front] == quadruplet[3]) back--;
                    }
                }
            
                // j ki condition j wale loop ke andar hi to likhega...
                // jumping over the duplicates of number 2
                while (j+1 < n  && nums[j+1] == nums[j]) j++;
            }
            // i ki condition i waale loop ke andar likhna hoga...
            // jumping over the duplicates of number 1
            while (i+1 < n && nums[i+1] == nums[i]) i++;

            // matlab front back i, j, kahi bhi duplicates nahi sahenge....
        }
        return res;
    }  
};



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> res; // To store the resulting quadruplets

        if (nums.empty()) return res; // If the input array is empty, return an empty result

        int n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort the array to simplify duplicate handling and enable two-pointer technique

        // Step 2: First loop for the first number in the quadruplet
        for (int i = 0; i < n; i++) {
            // Step 3: Second loop for the second number in the quadruplet
            for (int j = i + 1; j < n; j++) {
                // Calculate the remaining target after choosing nums[i] and nums[j]
                long long int target_2 = (1LL * target) - (1LL * nums[i]) - (1LL * nums[j]); 

                // Initialize two pointers for the remaining two numbers
                int l = j + 1; 
                int r = n - 1; 

                // Step 4: Two-pointer approach to find pairs that sum to target_2

                while (l < r) {

                    int two_sum = nums[l] + nums[r]; 

                    if (two_sum < target_2) {
                        // If the sum is less than the target, move the left pointer forward to increase the sum
                        l++;
                    } 
                    
                    else if (two_sum > target_2) {
                        // If the sum is greater than the target, move the right pointer backward to decrease the sum
                        r--;
                    } 
                    
                    else {
                        // If the sum matches the target, we found a valid quadruplet
                        vector<int> quadruplet(4, 0);

                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[l];
                        quadruplet[3] = nums[r];

                        res.push_back(quadruplet); // Add the quadruplet to the result

                        // Skip duplicates for the third number
                        while (l < r && nums[l] == quadruplet[2]) l++;

                        // Skip duplicates for the fourth number
                        while (l < r && nums[r] == quadruplet[3]) r--;
                    }
                }

                // Skip duplicates for the second number
                while (j + 1 < n && nums[j + 1] == nums[j]) j++;
            }

            // Skip duplicates for the first number
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return res; // Return the list of all unique quadruplets
    }
};

/*
**Explanation:**

1. **Sort the array:** Sorting simplifies handling duplicates and allows for an efficient two-pointer approach.
2. **Outer loops for first and second numbers:** Use nested loops to fix the first two elements of the quadruplet.
3. **Two-pointer approach for remaining numbers:** After fixing two numbers, use two pointers (`l` and `r`) to find pairs that sum to the remaining target (`target_2`).
4. **Duplicate handling:** Skip duplicates for all four numbers (nums[i], nums[j], nums[l], nums[r]) to avoid duplicate quadruplets.
5. **Complexity:** Sorting takes `O(n log n)`. The nested loops and two-pointer approach take `O(n^3)` in total.

This algorithm efficiently finds all unique quadruplets that sum up to the given target.
*/


