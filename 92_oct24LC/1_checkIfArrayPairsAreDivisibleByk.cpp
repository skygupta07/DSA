#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map <int, int> freq;

        for (auto el: arr){
            int rem = el %k;

            if (rem < 0) rem += k;

            freq[rem]++;
        }

        if (freq[0]%2 != 0) return false;

        for (int i=1; i<=k/2; i++){ // all possible remainders
            if (freq[i] != freq[k-i]){
                return false;
            }
        }

        return true;
    }
};


/*
(a+b) % k == 0   ===> (a%k + b%k) gives either 0 or k
count the freq of remainder of each array element 

if (rem == 0) then its freq should be even
if (rem == i) then its freq should be equal to (rem == k-i)

*/