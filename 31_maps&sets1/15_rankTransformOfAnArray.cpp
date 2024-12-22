#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> ans(arr.size());   // when I need to pick
            //  or play with the  index of the vector ...
            // we will need to mention the size of vector ...
        if (arr.size() == 0) return ans;

       vector <int> v;
       v = arr; // this is how we copy a array 

        sort(v.begin() , v.end()); 

        unordered_map <int, int> mp;

        int rank = 1;   // thresholds
        mp[v[0]] = 1;

        for (int i=1; i<v.size(); i++){
            if (v[i] == v[i-1]){    // if consecutive elements are same they will share the same rank
                mp[v[i]] = rank;
            }
            else{
                rank++;
                mp[v[i]] = rank;
            }
        }

        

        for (int i=0; i<arr.size(); i++){
            ans[i] = mp[arr[i]];
        }
        
        return ans; 
    }
};