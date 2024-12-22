#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int lastone = 32; // Initialize lastone to an invalid index (greater than any valid bit index)
        int ans = 0;      // Variable to store the maximum distance
        for (int i = 0; i < 32; i++) { // Loop over all 32 bits (assuming n is a 32-bit integer)
            if (n & (1 << i)) {  // Check if the ith bit of n is 1
                ans = max(ans, i - lastone); // Update the maximum gap if this distance is larger
                lastone = i;  // Update lastone to the current index of 1
            }
        }
        return ans;  // Return the maximum gap found
    }
};
