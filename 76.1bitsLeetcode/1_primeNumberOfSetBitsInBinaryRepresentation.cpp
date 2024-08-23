#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n){
        int cnt = 0;
        while (n>0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }

    bool isPrime(int n){
        if (n == 0 || n == 1) return false;

        for (int i=2; i*i<=n; i++){
            if (n%i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for (int i=left; i<=right; i++){
            int setBits = countSetBits(i);
            if (isPrime(setBits)) ans++;
        }

        return ans;
    }
};