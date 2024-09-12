#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorrResult = start ^ goal;

        // count the number of different bits === count the number of 1s in the xor of the result...

        int count = 0;
        while (xorrResult > 0){
            count += (xorrResult & 1);

            xorrResult = xorrResult >> 1;
        }

        return count;
    }
};





class Solution {
public:
    vector <int> numToBin(int n){
        vector <int> result(32, 0);

        int j = 31;
        while (n > 0){
            result[j--] = (n%2);
            n = n / 2;
        }

        return result;
    }

    int minBitFlips(int start, int goal) {
        vector <int> binStart = numToBin(start);
        vector <int> binGoal = numToBin(goal);


        int count = 0;
        for (int i=0; i<32; i++){
            count += binStart[i] ^ binGoal[i];
        }

        return count;
    }
};


/*
brute force int to binary 
then iterate and count different

*/