#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<=n-2; i++){
            for (int j=i+1; j<=n-1; j++){
                if (__gcd(nums[i] , nums[j]) == 1){
                    return true;
                }
            }
        }
        return false;
    }
};



/*
har do pair pe check kara jaise hi gcd 1 aagya loop break kar do...

yaha par mai O(n^2) wala kaam kar raha tha.... but same cheej threshold zeroth element and then
single loop mai iterate karte huye bhi update kar sakta tha.....
*/



class Solution {
public:
    bool isGoodArray(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;

        int current_gcd = nums[0];
        for (int i = 1; i < n; ++i) {
            current_gcd = __gcd(current_gcd, nums[i]);
            if (current_gcd == 1) {
                return true;
            }
        }
        return current_gcd == 1;    // or return false bhi chalega... simply non void wala bachane ke liye kiya....
    }
};