#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);  // Tracks count of each bit position in the current window
        int left = 0, minLength = INT_MAX;  // Left boundary of window and min length of subarray

        // Expand the window with the 'right' pointer
        for (int right = 0; right < nums.size(); ++right) {
            updateBits(count, nums[right], 1);  // Add nums[right] to the current window

            // Shrink the window from the left while the condition is met
            while (left <= right && getVal(count) >= k) {
                minLength = min(minLength, right - left + 1);  // Update minimum length if valid
                updateBits(count, nums[left], -1);  // Remove nums[left] from the current window
                left++;  // Move left boundary of window forward
            }
        }

        return minLength == INT_MAX ? -1 : minLength;  // Return -1 if no valid subarray found
    }

private:
    // Updates the bit counts in `count` based on the number `num`
    void updateBits(vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; ++i) {
            if ((num >> i) & 1) {  // Check if the i-th bit is set in num
                count[i] += val;   // Increment or decrement the bit count based on val
            }
        }
    }

    // Calculates the bitwise OR value of the current window based on `count`
    int getVal(const vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (count[i] > 0) {  // If any number in the window has the i-th bit set
                ans |= (1 << i); // Set the i-th bit in the result
            }
        }
        return ans;
    }
};
