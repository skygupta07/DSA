#include <bits/stdc++.h>
using namespace std;

class Solution { // gives tle
public:
    long long maximumHappinessSum(vector<int>& happiness, int k){
        long long ans = 0;  // mistake 1 -> I created the variable long long ans , but didn't initialise it..


        // descending order mai sort karne ka rambaan hai teessra inbuilt comparator greater <int>() function pass kardo....
        sort(happiness.begin() , happiness.end() , greater<int>());
        int i = 0;
        while (k--){
            ans += happiness[i];

            // decreasing the happiness of next children
            for (int j=i+1; j<happiness.size(); j++){
                if (happiness[j]>0) happiness[j]--;
            }
            i++;
        }
        
        return ans;
    }
};

// correct optimal ans

class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<int>());
        int i = 0;
        long long ans = 0;

        while(k--) {
            h[i] = max(h[i] - i, 0);
            ans += h[i];
            i++;
        }
        return ans;
    }
};