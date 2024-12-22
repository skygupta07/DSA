#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Convert decimal to binary and store in a vector
    void decToBin(int decNum, vector<int>& binNum) {
        while (decNum > 0) {
            binNum.push_back(decNum % 2);
            decNum /= 2;
        }
        // The binary representation is in reverse order, so we need to reverse it
        reverse(binNum.begin(), binNum.end());
    }

    // Convert binary stored in a vector to decimal
    int binToDec(vector<int>& binNum) {
        int sum = 0;
        int n = binNum.size();
        for (int i = 0; i < n; i++) {
            sum += binNum[i] * (1 << (n - 1 - i));
        }
        return sum;
    }

    int findComplement(int num) {
        vector<int> binNum;
        decToBin(num, binNum);

        // Invert the binary digits (complement)
        for (int i = 0; i < binNum.size(); i++) {
            binNum[i] = !binNum[i];
        }

        // Convert the complemented binary number back to decimal
        int ans = binToDec(binNum);

        return ans;
    }
};