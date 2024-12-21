#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;
        
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += arr[j];
                if (sum == target) count++;
            }
        }
        return count;
    }
};




class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector <int> pref(n,0);

        pref[0] = arr[0];
        for (int i=1; i<n; i++){
            pref[i] = arr[i] + pref[i-1];
        }

        unordered_map <int, int> mp;
        int count = 0;

        for (int i=0; i<n; i++){
            if (pref[i] == k) count++;

            int rem = pref[i] - k;
            if (mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[pref[i]]++;
        }
        return count;
    }
};



/*
calculated prefix sum -> since subarray wala prefix sum ke dost wala question...
at any moment if prefixSum[i] == k   count ++

else sabhi element ka rem find kara and dekha ki kya remaining element present hai...
agar present hai to kitni baar present hai ...uska utni baar contribution dedo count mai....

*/