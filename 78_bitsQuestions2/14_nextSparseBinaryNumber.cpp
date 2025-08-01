// nextSparseBinaryNumber.cpp


/*

Suppose a number has consecutive 1s in binary (like 110, 1110, etc). These are not sparse.
To convert them to a sparse number, we push the problem forward by setting a higher bit to 1 
(carry forward) and resetting the problematic bits.

Socha jaaye toh ye greedy strategy hai — jaise hi 2 consecutive 1s mile, 
agla bit 1 kar do aur peeche sabko 0.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int nextSparse(int n){

        vector <int> bits;

        // 🔹 Step 1: Convert n to binary and store in 'bits' vector
        // Store bits from LSB to MSB (least to most significant)
        int temp = n;

        while (temp > 0) {
            bits.push_back(temp & 1);  // extract the last bit (0 or 1)
            temp >>= 1;                // right shift to process next bit
        }

        bits.push_back(0);  // Extra 0 to handle edge cases like carry

        // 📌 Now, bits[i] has ith bit of the number (starting from LSB)

        int numBits = bits.size(); // number of bits
        
        int lastFinalIdx = 0;  // This keeps track of the last safe (no change needed) index

        // 🔹 Step 2: Traverse bits and fix where two consecutive 1s are found
        for (int i = 1; i < numBits - 1; i++) {

            // Condition to check if bits[i] and bits[i-1] are both 1
            // and bits[i+1] is 0 → potential problem of consecutive 1s
            if (bits[i] == 1 && bits[i - 1] == 1 && bits[i + 1] != 1) {

                // 🔧 Fix: carry forward the 1 to next bit
                bits[i + 1] = 1;

                // Reset all bits from i down to lastFinalIdx to 0
                // Because we are "correcting" the number from this point
                for (int j = i; j >= lastFinalIdx; j--) {
                    bits[j] = 0;
                }

                // Update lastFinalIdx so that we don’t touch corrected bits again
                lastFinalIdx = i + 1;
            }
        }

        // 🔹 Step 3: Convert modified bits vector back to integer
        int result = 0;
        
        for (int i = 0; i < numBits; i++) {
            result += (bits[i] << i);  // bits[i] * 2^i
        }

        return result;
    }
};
