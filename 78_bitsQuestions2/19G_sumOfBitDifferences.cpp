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
Explanation: All possible pairs of an array are 
(1, 1), (1, 3), (1, 5), (3, 1), (3, 3) (3, 5),(5, 1), (5, 3), (5, 5).
Sum of bit differences = 0 + 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0 = 8


Constraints:
1 ≤ n ≤ 1e5
1 ≤ arr[i] ≤ 1e5

*/


#include <bits/stdc++.h>
using namespace std;


// Class Solution encapsulates the logic
class Solution {
public:

    // Function to return sum of bit differences between all pairs
    int sumBitDifferences(vector <int> &arr) {
        int n = arr.size();   // Total elements in array
        int total = 0;        // Final answer: sum of all bit differences

        // --- Loop over all 32 bit positions ---
        for (int i = 0; i < 32; i++) {

            int setCount = 0;  // Count of numbers jisme i-th bit set hai (1 hai)

            // --- Traverse the entire array to count set bits at position 'i' ---
            for (int j = 0; j < n; j++) {
                // Agar i-th bit set hai, toh count badhao
                if (arr[j] & (1 << i)) {
                    setCount++;
                }
            }

            // Jo bit position 'i' par set nahi hain (i.e., 0), unka count
            int unsetCount = n - setCount;

            /*
            Har 'set' aur 'unset' bit pair ek dusre ke sath 1 bit-difference banayenge.
            i.e., agar 1 value me i-th bit 1 hai aur dusri me 0 hai, to difference = 1

            Total such pairs = setCount * unsetCount

            BUT, since (x, y) and (y, x) are **both** valid pairs, we multiply by 2

            For example:
                arr = [1, 2]
                (1, 2) and (2, 1) are 2 separate pairs
            */
            total += (2 * setCount * unsetCount);
        }

        // Final answer: sum of bit differences over all 32 bits
        return total;
    }
};
