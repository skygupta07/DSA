#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto q : queries){
            int xorr = 0;   // reason zero xor anything is anything...
            for (int i=q[0]; i<=q[1]; i++){
                xorr ^= arr[i]; 
            }
            ans.push_back(xorr);
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector <int> ans;
        
        vector <int> prefXorr(n,0);
        prefXorr[0] = arr[0];

        for (int i=1; i<n; i++){
            prefXorr[i] = arr[i]^prefXorr[i-1];
        }

        for (auto query : queries){
            int start = query[0];
            int end = query[1];

            ans.push_back(prefXorr[start] ^ prefXorr[end] ^ arr[start]);
        }

        return ans;
    }
};