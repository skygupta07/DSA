#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    void find(vector <int> &bit, int n){
        while (n > 0){
            bit.push_back(n%2);

            n = n/2;
        }

        reverse(bit.begin(), bit.end());
    }



    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        vector <int> bit;

        find(bit, n);

        int setBit = 0;
        
        for (int b : bit){
            if (b == 1) setBit++;
        }

        return (setBit == 1);

    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (__builtin_popcount(n) == 1);
    }
};

class Solution {
public:
    void find(int n, vector<int> &bit) {
        while (n > 0) {
            bit.push_back(n % 2);
            n = n / 2;
        }
        reverse(bit.begin(), bit.end());
    }

    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        vector<int> bit;
        find(n, bit);

        // Count number of 1s in the binary representation
        int count = 0;
        for (int b : bit) {
            if (b == 1) count++;
        }

        return count == 1;
    }
};



class Solution {
public:


    bool isPowerOfTwo(int n) {
        // power ko zero ko start se karenge...
        int i = 0;


        // jab tak condition false nahi hoti check karte raho...
        while(true){

            long long sq = pow(2,i);
            // agar power kam aa rahi to badhate chalo...
            if (sq < n) i++;

            else if (sq == n) return true;

            // iss case mai wo power cross kar gaya hoga uss number se..
            else return false;
        } 
    }
};

