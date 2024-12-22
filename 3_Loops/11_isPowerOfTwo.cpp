#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 0;
        while(true){
            long long sq = pow(2,i);
            if (sq < n) i++;
            else if (sq == n) return true;
            else return false;
        } 
    }
};

