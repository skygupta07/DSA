// countTheNumberOfFairPrice.cpp


/*

Given a 0-indexed integer array nums of size n and two integers lower and upper, 
return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and

lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).


Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 1e5
nums.length == n
-1e9 <= nums[i] <= 1e9
-1e9 <= lower <= upper <= 1e9


*/

// brute force -> gave tle

class Solution {
public:
    
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int sum = nums[i] + nums[j];
                if (sum >= lower && sum <= upper) {
                    count++;
                }

                if (sum > upper) break;  // Early exit if sum exceeds upper bound {valid : coz sort kar diya h to aage positive element hi milenge.... break early}
            }
        }

        return count;

    }
};


#include <bits/stdc++.h>  
using namespace std;

class Solution {
public:

    // Main function jo fair pairs count karega
    long long countFairPairs(vector <int> &nums, int lower, int upper) {
        int n = nums.size();  // vector ka size nikal liya

        // Step 1: Pehle array ko sort karenge so that hum binary search ka use kar sakein
        // Binary search sorted array pe hi kaam karta hai
        sort(nums.begin(), nums.end());

        long long count = 0;  // yeh variable final answer store karega — total fair pairs

        // Step 2: Har index i ke liye, hum dekh rahe hain ki uske baad wale elements 
        // me kaunse j valid hain
        
        for (int i = 0; i < n; i++) {

            // Requirement: lower <= nums[i] + nums[j] <= upper

            // subtracting nums[i] from all sides 

            // ⇒ lower - nums[i] <= nums[j] <= upper - nums[i]
            
            // So we calculate minimum and maximum values nums[j] can take
            int min_required = lower - nums[i];  // nums[j] should be >= min_required
            int max_required = upper - nums[i];  // nums[j] should be <= max_required

            // Step 3: Binary Search ka use karke valid range ka start and end dhundhna hai
            // lower_bound: pehla element >= min_required (inclusive range ka start)
            // upper_bound: pehla element > max_required (exclusive range ka end)

            // Important: search range start hoti hai i+1 se kyunki i < j hona chahiye
            auto lower_bound_it = lower_bound(nums.begin() + i + 1, nums.end(), min_required);

            auto upper_bound_it = upper_bound(nums.begin() + i + 1, nums.end(), max_required);

            // Step 4: Valid j values = number of elements between lower_bound_it and upper_bound_it
            // distance() STL ka function hai jo 2 iterators ke beech ka distance return karta hai
            count += distance(lower_bound_it, upper_bound_it);

            /*
                Example:
                suppose nums[i] = 1
                lower = 4, upper = 6

                → min_required = 3
                → max_required = 5

                After sorting:
                nums = [0,1,4,4,5,7]

                So we want to find how many nums[j] where j > i such that:
                3 <= nums[j] <= 5

                Binary Search se:
                lower_bound = iterator to first element >= 3
                upper_bound = iterator to first element > 5

                Difference of these = number of valid j's for current i
            */
        }

        // Final count return kar do
        return count;
    }
};
