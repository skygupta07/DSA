// 3Sum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not matter.


Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-10pow5 <= nums[i] <= 10pow5

*/

class Solution{
public:

    vector <vector<int>> threeSum(vector <int> &v){
        int n = v.size();
        vector <vector<int>> ans;

        // Step 1: Sort the array to enable two-pointer technique and handle duplicates easily
        sort(v.begin(), v.end());

        // Step 2: Iterate through the array up to n-3 since we need at least 3 numbers
        for (int i = 0; i <= n - 3; i++){

            // Skip duplicate values for the first element to avoid duplicate triplets
            // khud dekh rahe ho ki bahar wala loop zero se chala h.. aur aap v[i-1] bhi kar rahe ho...
            //  to obviously pehli condition to phir i > 0 wali deni hi padegi....

            if (i > 0 && v[i] == v[i - 1]) continue;

            // Step 3: Initialize two pointers
            int l = i + 1; // Left pointer starts just after the current index -> same i thodi le lega.. !!
            int r = n - 1; // Right pointer starts at the end of the array

            // Step 4: Use the two-pointer technique to find pairs that sum to -v[i]
            while (l < r) {
                int sum = v[i] + v[l] + v[r]; // Calculate the sum of the triplet

                // If the sum is less than zero, move the left pointer forward to increase the sum (isliye to array sort kari thi....)
                if (sum < 0) l++;

                // If the sum is greater than zero, move the right pointer backward to decrease the sum
                else if (sum > 0) r--;

                else {
                    // If the sum is zero, we've found a valid triplet
                    ans.push_back(vector <int> {v[i], v[l], v[r]});

                    // Step 5: Skip duplicates for the second (l) and third (r) elements

                    // aur ha hamesha left aur right jinka kaam do element search karke lana h..... aapas mai do gaj ki duri bhi banake chalenge.. chahe kahi jaye... kucch bhi ho jae..
                    // aasaan sabdo mai bolu to two pointers ke liye sabse best rehta h...
                    // l < r

                    while (l < r && v[l] == v[l + 1]) l++; // Skip duplicate values for l
                    while (l < r && v[r] == v[r - 1]) r--; // Skip duplicate values for r

                    // Move both pointers to find the next potential pair in general
                    l++;
                    r--;
                }
            }
        }

        return ans; // Return the list of all unique triplets
    }
};

/*

Explanation:
1. Sort the input array to simplify handling duplicates and enable the two-pointer approach.
2. Traverse the array with an outer loop to fix the first element (v[i]) of the triplet.
3. Use two pointers (l and r) to find pairs that, along with v[i], sum to zero.

4. Handle duplicate elements carefully for both the first, second, and third elements of the triplet.
5. Adjust pointers (l++, r--) after finding a valid triplet or when the sum is too low/high.

The overall complexity is O(n^2), where sorting takes O(n log n) and the
two-pointer traversal for each element takes O(n).

*/
