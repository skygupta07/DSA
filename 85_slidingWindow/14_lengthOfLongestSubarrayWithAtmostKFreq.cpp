#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int ans = 0;
        int i=0, j=0;
        int n = nums.size();

        while (j<n){
            mp[nums[j]]++;  // increasing the freqency of jth element..

            // in case if frequency of element increased then i will come and maintain..
            while (i<=j && mp[nums[j]] > k){
                mp[nums[i]]--;  // decreasing ith element impact as we are removing it out of window...
                i++;
            }


            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

/*

standard template aapke sliding window ka...
i, j dono ko initially zero se start karwaya ...

then hamesha j ko move karenge ...... i aapka musibat padne par kaam dikhayega...
isliye beech mai i ki condition likhni hogi....

i ko aage badhane se ya usko increase karne se agar koi impact aa raha hoga dusre variable pe to usko handle 
karenge.....

sliding window mai window move karti hai to simultaneously variables bhi update hote rehte ...hai....


two pointer algorithm lagega....(inc, dec, inc-dec, dec-inc)
reason when you are filling element in the map...then frequency of elements is always in increasing mode...

length of sliding window from i to j is i-j+1

*/