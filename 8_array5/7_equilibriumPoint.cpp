// equilibriumPoint.cpp

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
Constraints:


3 <= arr.size() <= 1e5
-1e4 <= arr[i] <= 1e4

*/

int main() {
    return 0;
}

class Solution {
  public:

    // Function to find equilibrium point in the array.
    int findEquilibrium(vector <int> &arr) {
        int leftSum = 0;
        int rightSum = 0;

        int totalSum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            totalSum = totalSum + arr[i];
        }
        
        for(int i = 0; i < arr.size(); i++){ 
            // as per the question current element ko exclude hi rakhna h...
            rightSum = totalSum - leftSum - arr[i];

            if (leftSum == rightSum) return i;

            leftSum = leftSum + arr[i];
        }
        return -1;
    }
};


class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        
        vector <int> pref(n);
        pref[0] = 0;
        
        vector <int> suff(n);
        suff[n-1] = 0;
        
        for (int i=1; i<n; i++){
            pref[i] = arr[i-1] + pref[i-1];
        }
        
        for (int i=n-2; i>=0; i--){
            suff[i] = arr[i+1] + suff[i+1];
        }
        
        for (int i=0; i<n; i++){
            if (pref[i] == suff[i]) return i;
        }
        
        return -1;
    }
};

/*
prefSum except self
suffSum except self

iterate and see if they are equal at any point...
return that idx

or return -1

*/