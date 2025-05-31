// productExceptSelf
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        
        vector <int> prefProd(n, 1);  // prefix product array except self
        vector <int> suffProd(n, 1);  // suffix product array except self
        
        for (int i=1; i<n; i++){
            prefProd[i] = arr[i-1] * prefProd[i-1];
        }
        
        for (int i=n-2; i>=0; i--){
            suffProd[i] = arr[i+1] * suffProd[i+1];
        }
        
        vector <int> ans(n, 0);
        
        for (int i=0; i<n; i++){
            ans[i] = prefProd[i] * suffProd[i];
        }
        
        return ans;
        
    }
};