#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) 
such that the sum of all elements before that index is the same as the sum of elements after it. 
Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.

Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.

Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.

*/


class Solution {
public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        vector <int> prefSumExceptSelf(n, 0);
        vector <int> suffSumExceptSelf(n, 0);
        
        prefSumExceptSelf[0] = 0;
        for (int i=1; i<n; i++){
            // ha expect self wale mai pehle wale ka sum add karna hai
            prefSumExceptSelf[i] = arr[i-1] + prefSumExceptSelf[i-1];
        }
        
        suffSumExceptSelf[n-1] = 0;
        for (int j=n-2; j>=0; j--){

            suffSumExceptSelf[j] = arr[j+1] + suffSumExceptSelf[j+1];
        }
        
        for (int i=0; i<n; i++){
            if (prefSumExceptSelf[i] == suffSumExceptSelf[i]) return i;
        }
        
        return -1;    
    }
};