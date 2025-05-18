#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
    
            for (int i=16; i>=0; i--){
                int x = pow(3, i);
    
                if (n >= x) n -= x;
    
                if (n == 0) return true;
            }
    
            return false;
        }
    };