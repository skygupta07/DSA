#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        int maxi = INT_MIN; // Initialize maximum sum to a very small value
        
        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            int current_sum = 0; // Reset current sum for each starting point
            
            // Traverse the array in a circular manner
            for (int j = 0; j < n; j++) {
                int idx = (i + j) % n; // Wrap-around using modulo operator
                current_sum += arr[idx]; // Add current element to sum
                maxi = max(maxi, current_sum); // Update the maximum sum
            }
        }
        
        return maxi; // Return the maximum circular subarray sum
    }
};



// if i == n -1  -> can chose element as first element.
/*
har element ko starting element banne ka mauka diya...
jaha se bhi start hoga just uske ek peeche wale element tak jaaega..
aur iterate karte waqt mai hi global maximum variable ko maximize karte rehna...

*/



--------------- 
