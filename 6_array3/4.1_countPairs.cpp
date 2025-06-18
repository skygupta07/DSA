#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        
        unordered_map <int, int> mp;
        int count = 0;
        
        for (int i=0; i<n; i++){
            int complementEl = target - arr[i];
            
            if (mp.find(complementEl) != mp.end()){
                count += mp[complementEl];
            }
            // mila to current elment h, accha to map mai bhi wahi dalenge..
            mp[arr[i]]++;
        }
        
        return count;
    }
};

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
       unordered_map <int, int> mp;     // el , freq
        int n = arr.size();
        int count = 0;
        
       for (int i=0; i<n; i++){
           int rem = target - arr[i];
           
           if (mp.find(rem) != mp.end()) count += mp[rem]; // add its freq
           
           mp[arr[i]]++;
       }
       
       return count;
    }
};