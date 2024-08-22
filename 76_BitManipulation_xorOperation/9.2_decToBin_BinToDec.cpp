#include <bits/stdc++.h>
using namespace std;



void decToBin(int decNum, vector<int> &binNum){
    while (decNum > 0){
        binNum.push_back(decNum % 2);
        decNum /= 2;
    }
    // The binary representation is in reverse order, so we need to reverse it
    reverse(binNum.begin(), binNum.end());
}

// Convert binary stored in a vector to decimal
int binToDec(vector<int> &binNum){
    int sum = 0;
    int n = binNum.size();
    for (int i = 0; i < n; i++){
        sum += binNum[i] * (1 << (n - 1 - i));
    }
    return sum;
}