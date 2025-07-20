// sumPairClosestToTarget.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], 
where a<=b whose sum is closest to target.

Note: Return the pair in sorted order and if there are multiple such pairs 
return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]

Explanation: As 5 + 20 = 25 is closest to 25.

Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]

Explanation: As (4, 7) and (2, 7) both are closest to 10, 
but absolute difference of (2, 7) is 5 and (4, 7) is 3. 
Hence, [2, 7] has maximum absolute difference and closest to target. 


Input: arr[] = [10], target = 10
Output: []

Explanation: As the input array has only 1 element, return an empty array.


Constraints:
1 <= arr.size() <= 2*1e5
0 <= target<= 2*1e5
0 <= arr[i] <= 1e5

*/



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