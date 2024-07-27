#include <bits/stdc++.h>
using namespace std;

// Function to convert a decimal number to binary representation
void decToBin(int decNum, vector<int>& binNum) {
    while (decNum > 0) {
        int idx = 0;
        // Find the highest power of 2 less than or equal to decNum
        while (decNum >= (1 << idx)) {
            idx++;
        }
        // Set the corresponding binary position to 1
        binNum[idx - 1] = 1;
        // Subtract the value of the highest power of 2 from decNum
        decNum -= (1 << (idx - 1));
    }
}

// Function to display the binary number stored in a vector
void display(const vector<int>& binNum) {
    for (int i = 0; i < binNum.size(); i++) {
        cout << binNum[i] << " ";
    }
    cout << "\n";
}

int main() {
    int decNum = 8; // Decimal number to be converted
    vector<int> binNum(32, 0); // Vector to store binary representation (32 bits)

    decToBin(decNum, binNum); // Convert decimal to binary
    display(binNum); // Display the binary number

    return 0;
}


// - ------ - -- -- -------


#include <iostream>
#include <vector>
using namespace std;

// Function to convert a decimal number to binary representation
void decToBin(int decNum, vector<int>& binNum) {
    while (decNum > 0) {
        // Find the position of the highest set bit
        int idx = log2(decNum);
        // Set the corresponding binary position to 1
        binNum[idx] = 1;
        // Subtract the value of this bit from decNum
        decNum -= (1 << idx);
    }
}

// Function to display the binary number stored in a vector
void display(const vector<int>& binNum) {
    for (int bit : binNum) {
        cout << bit << " ";
    }
    cout << "\n";
}

int main() {
    int decNum;
    cout << "Enter a decimal number: ";
    cin >> decNum; // Read the decimal number from user

    // Determine the number of bits needed
    int numBits = log2(decNum) + 1;
    vector<int> binNum(numBits, 0); // Vector to store binary representation

    decToBin(decNum, binNum); // Convert decimal to binary
    display(binNum); // Display the binary number

    return 0;
}
