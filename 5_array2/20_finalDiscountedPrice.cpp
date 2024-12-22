#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        vector <int> nse(n, 0);   // just next smaller element...is our discount


        for (int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if (prices[j] <= prices[i]){
                    nse[i] = prices[j];
                    break;
                }
            }
        }

        vector <int> ans = prices;

        for (int i=0; i<n; i++){
            ans[i] -= nse[i];
        }

        return ans;

    }
};