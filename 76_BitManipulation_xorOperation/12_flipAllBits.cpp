#include <bits/stdc++.h>
using namespace std;

// Function to display the binary representation
void display(const vector<int>& binNum) {
    for (int bit : binNum) {
        cout << bit << " ";
    }
    cout << "\n";
}

// Function to convert a decimal number to binary
void decToBin(int decNum, vector<int>& binNum) {
    fill(binNum.begin(), binNum.end(), 0);  // Reset binNum for reuse
    int idx = binNum.size() - 1;
    while (decNum > 0) {
        binNum[idx--] = decNum % 2;
        decNum /= 2;
    }
}

// Function to flip all bits of x - (flip karna matlab 1 ke saath xor kar dena)
void flipAllBits(int &x) {
    int numBits = log2(x) + 1;  // Find the number of bits in the binary representation of x
    int allOnes = (1 << numBits) - 1;  // Create a bitmask of all 1s with the same number of bits
    x = x ^ allOnes;  // XOR x with the bitmask to flip all bits
}

int main() {
    int n = 56;

    int numBits = log2(n) + 1;
    vector<int> binNum(numBits, 0); // Vector to store binary representation
    decToBin(n, binNum);
    display(binNum);

    flipAllBits(n);
    decToBin(n, binNum);
    display(binNum);

    return 0;
}
