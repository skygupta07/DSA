//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// brute force => gives tle
class Solution {
  public:
    int maximumProfit(vector<int> &arr) {
        int n = arr.size();
        // code here
        
        vector <int> profits;
        
        for (int i=0; i<n-1; i++){
            int maxi = 0;
            
            for (int j=i+1; j<n; j++){
                maxi = max(maxi, arr[j] - arr[i]);
            }
            
            profits.push_back(maxi);
        }
        
        int ans = 0;
        
        for (int i=0; i<profits.size(); i++){
            ans = max(ans, profits[i]);
        }
        
        return ans;
    }
};



// kadane's algo ❌ Harshad Mehta algo ✅