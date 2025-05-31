#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: 
the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11


Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000


*/


// brute force gives tle

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int maxi = INT_MIN;

        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                maxi = max(maxi , values[i] + values[j] + i - j);
            }
        }

        return maxi;
    }
};




class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        // Edge case: if only two elements, directly return score
        if (n == 2) return values[0] + values[1] + 0 - 1;

        // Step 1: Prepare suffixMax array
        // suffixMax[j] will store maximum of (values[j] - j) from j to end
        vector<int> suffixMax(n);
        suffixMax[n - 1] = values[n - 1] - (n - 1);  // last element

        // Fill suffixMax from right to left
        for (int j = n - 2; j >= 0; j--) {
            // At every index, store max of current or the one ahead
            suffixMax[j] = max(suffixMax[j + 1], values[j] - j);
        }

        // Step 2: Iterate i from 0 to n - 2
        // For each i, we pick j = i + 1 to n-1, and already know max (values[j] - j) in suffix
        
        int maxScore = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            // (values[i] + i) is fixed for i, combine it with best (values[j] - j) ahead
            maxScore = max(maxScore, (values[i] + i) + suffixMax[i + 1]);
        }

        return maxScore;
    }
};
