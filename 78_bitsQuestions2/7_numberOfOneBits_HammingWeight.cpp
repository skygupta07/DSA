// numberOfOneBits_HammingWeight.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int hammingWeight(int n) {
            int ans = 0;

            while (n > 0){
                // agar last bit 1 hai to ans mai ek increase kiya...
                if (n & 1) ans += 1;  
                
                // next iteration ke liye naye bakre ko ready kiya...
                n = n >> 1;  
            }

            return ans;
        }
};