#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& v) {
        int n = v.size();
        int maxi = 0;

        for (int i=0; i<32; i++){
            int count = 0;
            for (auto el: v){
                if (el & (1<<i)){
                    count++;
                }
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }
};


/*

har bit pe gaye of ith candidate...

*/