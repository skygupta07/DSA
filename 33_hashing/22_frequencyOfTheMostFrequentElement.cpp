// frequencyOfTheMostFrequentElement.cpp


#include <bits/stdc++.h>
using namespace std;

/*

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, 
you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.


Example 1:

Input: nums = [1,2,4], k = 5
Output: 3

Explanation: Increment the first element three times and the second element two times to 
make nums = [4,4,4].
4 has a frequency of 3.


Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2

Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.


Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
 
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array to bring similar elements together
        sort(nums.begin(), nums.end());

        long long maxFreq = 0;             // Final answer
        unsigned long long currSum = 0;    // Sum of current window elements

        // Sliding window with two pointers: left and right
        for (long long left = 0, right = 0; right < nums.size(); right++) {
            currSum += nums[right]; // Add current element to the window sum // currentSum or subarraySum

            /*
             * Core condition:
             * We want to make all elements in the window equal to nums[right]
             * For that: Total required sum = nums[right] * window_size
             * If currSum + k (allowed increments) < required sum, then window is invalid
             * Toh left pointer ko aage badhao (window chhota karo)
             */

            while (currSum + k < static_cast<unsigned long long>(nums[right]) * (right - left + 1)) {
                currSum -= nums[left]; // Remove element from left
                left++;                // Shrink the window
            }

            // Update max frequency if current window is valid
            maxFreq = max(maxFreq, right - left + 1);
        }

        return int(maxFreq); // Final answer
    }
};



class Solution {
public:

        // mene pura dry run to kar liya .. magar ye samajh nahi aa rha ki ye kaun si kitab ki DSA h ??
        // issey yaad hi karna padega kya??
    
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
    
            int left = 0;  // Left pointer of sliding window
            long long subarraySum = 0;  // Sum of elements in the window
            
            int maxFreq = 1;  // Variable to store max frequency
    
            // Iterate with right pointer
            for (int right = 0; right < nums.size(); right++) {

                subarraySum += nums[right];  // Add current element to sum
                int subarrayLen = right - left + 1;  // Calculate window size
                
                // If the condition fails, shrink the window from the left
                while ( (long long)(nums[right] * subarrayLen) - subarraySum > k)  {
                    subarraySum -= nums[left];  // Remove leftmost element
                    left++;  // Move left pointer ahead
                    subarrayLen--;  // Adjust subarray length
                }

                maxFreq = max(maxFreq, subarrayLen);  // Update max frequency
            
            }
    
            return maxFreq;  // Return maximum frequency found
        }
    };
    