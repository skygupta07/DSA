#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        
        // If there is 0 or 1 element, the longest consecutive sequence is the size itself
        if (n <= 1) return n;

        // Sort the array to arrange the elements in increasing order
        sort(nums.begin(), nums.end());

        int ccs = 1; // `ccs` (current consecutive sequence) starts with 1 (a single element)
        int lcs = 1; // `lcs` (longest consecutive sequence) initialized to 1

        // Iterate through the sorted array
        for (int i = 1; i < n; i++) {
            // Skip duplicates to avoid counting the same number multiple times
            if (nums[i] != nums[i-1]) {
                // Check if the current number is consecutive to the previous one
                if (nums[i] == nums[i-1] + 1) {
                    ccs++; // Increase the length of the current consecutive sequence
                } else {
                    // Not consecutive, so update the longest sequence length
                    lcs = max(lcs, ccs);
                    ccs = 1; // Reset the current sequence length
                }
            }
        }

        // After the loop, check the maximum length one last time to account for
        // a sequence that extends to the end of the array
        return max(lcs, ccs);
    }
};



// ----


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp; // Hash map to track if a number can start a sequence

        // Mark all numbers as `true` initially (potential sequence starters)
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = true;
        }

        // Identify numbers that cannot be the start of a sequence
        for (int i = 0; i < n; i++) {
            // If the number (nums[i] - 1) exists in the map, nums[i] cannot start a sequence
            if (mp.count(nums[i] - 1) > 0) {
                mp[nums[i]] = false; // Mark as false to indicate it's not a sequence starter
            }
        }

        int maxLen = 0; // Variable to track the length of the longest sequence

        // Iterate through the array to find sequences starting with valid numbers
        for (int i = 0; i < n; i++) {
            // Check if the current number is a sequence starter
            if (mp[nums[i]] == true) {
                int j = 0;    // Variable to iterate through the sequence
                int count = 0; // Length of the current sequence
                
                // Count the length of the sequence starting from nums[i]
                while (mp.count(nums[i] + j) > 0) {
                    j++;    // Move to the next number in the sequence
                    count++; // Increment the count for the sequence
                }

                // Update the maximum length if the current sequence is longer
                if (count > maxLen) maxLen = count;
            }
        }

        return maxLen; // Return the length of the longest consecutive sequence
    }
};
