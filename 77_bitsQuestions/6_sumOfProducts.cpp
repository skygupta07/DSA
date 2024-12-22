#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: 
calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.
*/


#define ll long long int
class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        vector <ll> freq(32,0);
        ll ans = 0;
        
        for (int i=0; i<n; i++){
            ll curr = arr[i];
            for (int j=0; j<32; j++){
                if ((curr>>j)&1){
                    ans +=(freq[j]*1LL*(1LL<<j));
                    freq[j]++;
                }
            }
        }
        return ans;
    }
};