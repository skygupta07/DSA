#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int specialArray(vector<int>& nums) {
            int n = nums.size();
            
            // Step 1: Sort the array to allow binary search
            sort(nums.begin(), nums.end());
    
            // Lambda function to find the number of elements >= currNum using binary search
            auto findNumberOfNums = [&](int currNum) -> int {
                int left = 0, right = n - 1;
                int firstIdx = n;  // Default to 'n' if no valid index is found
    
                // Binary search to find the first index where nums[mid] >= currNum
                while (left <= right) {
                    int mid = left + (right - left) / 2;
    
                    if (nums[mid] >= currNum) {
                        firstIdx = mid;  // Store the current index
                        right = mid - 1;  // Move left to find the smallest index
                    } else {
                        left = mid + 1;  // Move right as we need a larger number
                    }
                }
    
                return n - firstIdx;  // Count of numbers greater than or equal to currNum
            };
    
            // Step 2: Iterate through possible values of X from 1 to n
            for (int candidateNumber = 1; candidateNumber <= n; candidateNumber++) {
                // Check if exactly 'candidateNumber' elements are >= 'candidateNumber'
                if (candidateNumber == findNumberOfNums(candidateNumber)) 
                    return candidateNumber; // Found a valid special number
            }
    
            // Step 3: If no valid number is found, return -1
            return -1;
        }
    };
    