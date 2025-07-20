// maximumProductSubarray.cpp

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        if (n == 0) return 0;
        
        int maxi = arr[0];
        int mini = arr[0];
        int result = arr[0];
        
        for (int i=1; i<n; i++){
            if (arr[i] < 0) swap (maxi, mini);
            
            
            // ya to individual mai dum h to wo karwa de.. ya phir 
            // previous product ke saath multiply hoke max karwa de...
            maxi = max(arr[i] , arr[i] * maxi);
            mini = min(arr[i] , arr[i] * mini);
            
            // for global maximum 
            result = max(result, maxi);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends




-------- 


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();
        
        // Function to calculate max subarray sum using Kadane's algorithm
        auto kadane = [](vector<int>& nums) {
            int max_sum = nums[0], current_sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                current_sum = max(nums[i], current_sum + nums[i]);
                max_sum = max(max_sum, current_sum);
            }
            return max_sum;
        };
        
        // Case 1: Maximum subarray sum without wrapping
        int max_kadane = kadane(arr);
        
        // Case 2: Maximum subarray sum with wrapping
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i]; // Invert the array to find minimum subarray sum
        }
        
        // Minimum subarray sum becomes maximum of inverted array
        int min_subarray_sum = kadane(arr);
        int max_wrap = total_sum + min_subarray_sum; // Total sum - (-min_subarray_sum)
        
        // If all elements are negative, max_wrap will be 0
        if (max_wrap == 0) return max_kadane;
        
        // Return the maximum of both cases
        return max(max_kadane, max_wrap);
    }
};

