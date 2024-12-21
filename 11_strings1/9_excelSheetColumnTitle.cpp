#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = ""; // String to store the resulting column title

        // Continue until there are no more digits to process
        while (n > 0) {
            // Decrement n by 1 to make it 0-indexed
            n--;

            // Calculate the remainder (0-25), representing the letter position
            int rem = n % 26;

            // Append the corresponding character ('A' + rem) to the result
            ans += ('A' + rem);

            // Update n by dividing it by 26 (move to the next higher "place")
            n /= 26;
        }

        // The result is built in reverse order, so reverse it before returning
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
