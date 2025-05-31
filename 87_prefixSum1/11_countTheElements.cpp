#include <bits/stdc++.h>
using namespace std;
  
vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        
                                vector<int> pre(100002,0);
        for(int i=0;i<n;i++){
            pre[b[i]]++;
        }

        for(int i=1;i<100002;i++){
            pre[i] += pre[i-1];
        }

        vector<int> ans;

        for(const auto &i : query){
            ans.push_back(pre[a[i]]);
        }
        
        return ans;
}


    