// sumOfBitDifferences.cpp

/*

Given an array integers arr[], containing n elements, 
find the sum of bit differences between all pairs of element in the array. 

Bit difference of a pair (x, y) is the count of different bits at the same positions 
in binary representations of x and y.

Note: (x, y) and (y, x) are considered two separate pairs.

Examples:

Input: arr[] = [1, 2]
Output: 4

Explanation: All possible pairs of an array are (1, 1), (1, 2), (2, 1), (2, 2). 
Sum of bit differences = 0 + 2 + 2 + 0 = 4


Input: arr[] = [1, 3, 5]
Output: 8

Explanation: All possible pairs of an array are (1, 1), (1, 3), (1, 5), (3, 1), 
(3, 3) (3, 5),(5, 1), (5, 3), (5, 5).

Sum of bit differences = 0 + 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0 = 8


Constraints:
1 ≤ n ≤ 1e5
1 ≤ arr[i] ≤ 1e5

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sumBitDifferences(vector<int>& arr) {
        int ans = 0;

        // traverse over all bits
        for (int i = 0; i < 32; i++) {
            // count number of elements with i'th bit set
            int count = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i)))
                    count++;

            // Add "count * (n - count) * 2" to the answer
            ans += (count * (n - count) * 2);
        }

        return ans;
    }
};