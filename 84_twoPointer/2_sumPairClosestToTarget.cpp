#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {}; // No pair exists in case of insufficient elements

        sort(arr.begin(), arr.end()); // Sort the array
        
        int left = 0, right = n - 1; 

        int closestDiff = INT_MAX;   // Minimum difference between sum and target
        int maxAbsDiff = INT_MIN;    // Maximum absolute difference between a and b

        vector <int> result;          // Store the result pair

        while (left < right){

            int sum = arr[left] + arr[right];
            int diff = abs(sum - target); // Difference from the target

            if (diff < closestDiff || (diff == closestDiff && abs(arr[right] - arr[left]) > maxAbsDiff)) {
                // Update result if we find a closer sum or if the difference is the same but absolute diff is greater
                
                closestDiff = diff;
                maxAbsDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
                
            }

            // Move pointers to find other pairs
            if (sum < target) left++;
            else right--;
        }

        return result;
    }
};