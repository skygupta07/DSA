#include <bits/stdc++.h>
using namespace std;

int longestDangerousRange(vector<int>& height, int n)
{
    if (n < 2) return n;

    int maxLen = 1; // At least one hill is trivially a dangerous range
    int up = 1, down = 1; // To track increasing and decreasing subsequences

    for (int i = 1; i < n; i++) {
        if (height[i] > height[i - 1]) {
            up = down + 1; // Increase "up" subsequence length
            down = 1;      // Reset "down" subsequence
        } else if (height[i] < height[i - 1]) {
            down = up + 1; // Increase "down" subsequence length
            up = 1;        // Reset "up" subsequence
        } else {
            up = down = 1; // Reset both for equal heights
        }

        maxLen = max(maxLen, max(up, down)); // Update the max length
    }

    return maxLen;
}
