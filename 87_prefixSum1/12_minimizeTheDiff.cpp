// minimizeTheDifference.cpp

/*

You are given an array arr of size n. You have to remove a subarray of size k, 
such that the difference between the maximum and minimum values of the remaining array is minimized.
Find the minimum value obtained after performing the operation of the removal of the subarray 
and return it.

Example 1:

Input:
n = 5
k = 3

arr = {1, 2, 3, 4, 5}

Output: 
1

Explanation: 
We can remove first subarray of length 3(i.e. {1, 2, 3}) then remaining array will be {4,5} 
and the difference of maximum and minimum element will be 1 i.e 5 - 4 = 1


Example 2:

Input:
n = 6
k = 3

arr = {2, 3, 1, 4, 6, 7}

Output: 
2

Explanation:
If we remove the subarray {2,3,1} then remaining array will be {4,6,7} and the difference  = 7-4 = 3
If we remove the subarray {3,1,4} then remaining array will be {2,6,7} and the difference  = 7-2 = 5
If we remove the subarray {1,4,6} then remaining array will be {2,3,7} and the difference  = 7-2 = 5
If we remove the subarray {4,6,7} then remaining array will be {2,3,1} and the difference  = 3-1 = 2

So the answer will be min(3,5,5,2) = 2

Your Task: 
You have to complete the function minimizeDifference( ), 
which takes two integers n and k and an integer array arr of size n. 
You have to return the minimum difference of maximum and minimum elements of the remaining array 
after removing one k length subarray of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
2 <= n <= 1e6
1 <= k <= n-1
0 <= arr[i] <= 1e9

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minimizeDifference(int n, int k, vector <int> &a){
        
        // Arrays to hold the minimum and maximum values of the prefix and suffix.
        vector <pair<int, int>> prefixMinMax(n), suffixMinMax(n);
        
        // Initializing prefix and suffix arrays.
        prefixMinMax[0] = {a[0], a[0]};
        suffixMinMax[n - 1] = {a[n - 1], a[n - 1]};
        
        for (int i = 1; i < n; i++) {

            int revIdx = n - i - 1;

            prefixMinMax[i] = {
                min(prefixMinMax[i - 1].first, a[i]),
                max(prefixMinMax[i - 1].second, a[i])
            };

            suffixMinMax[revIdx] = {
                min(suffixMinMax[revIdx + 1].first, a[revIdx]),
                max(suffixMinMax[revIdx + 1].second, a[revIdx])
            };

        }
        
        // Start with the difference for the first possible removal scenario.
        int minDiff = INT_MAX;

        // Compute the minimum difference considering the remaining segments after each potential removal.
        for (int i = 0; i <= n - k; i++){

            int minElem = i == 0 ? suffixMinMax[i + k].first : (i + k == n ? prefixMinMax[i - 1].first : min(prefixMinMax[i - 1].first, suffixMinMax[i + k].first));
            int maxElem = i == 0 ? suffixMinMax[i + k].second : (i + k == n ? prefixMinMax[i - 1].second : max(prefixMinMax[i - 1].second, suffixMinMax[i + k].second));
            
            minDiff = min(minDiff, maxElem - minElem);
        }
        
        return minDiff;
    }
};