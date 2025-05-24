#include <bits/stdc++.h> // Sabhi standard libraries include ho jati hain isme
using namespace std;


/*

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10pown.


Example 1:

Input: n = 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100,
excluding 11,22,33,44,55,66,77,88,99


Example 2:

Input: n = 0
Output: 1
 
Constraints:

0 <= n <= 8

*/



class Solution {
public:

    // Ye function 'nPr' calculate karta hai => n * (n-1) * (n-2) ... (n-r+1)
    int permutation(int n, int r){
        if (r == 0) return 1; // Base case: agar r == 0, toh ek hi permutation possible hai
        else return n * permutation(n - 1, r - 1); // Recursive call se nPr calculate ho raha hai
    }

    // Main function jo count karega kitne numbers possible hain jisme digits unique hain
    int countNumbersWithUniqueDigits(int n) {
        // (n = 0) => 10pow0 = 1 =>  0 <= x < 1  => only number 0 is possible , i.e. ek number hi possible h
        int sum = 1; // 0 digit ke liye ek hi number possible hai i.e. 0

        if (n > 0){
            // Kyuki 10 se zyada digits possible nahi (0-9), toh max limit 10 hai
            int end = (n > 10) ? 10 : n;

            // Loop chalega 0 se leke end-1 tak
            for (int i = 0; i < end; i++) {
                // 9 options hote hain first digit ke liye (0 chod ke)
                // Baaki i digits ke liye hum permutation calculate kar rahe hain (9 digits me se i choose karna)
                sum += 9 * permutation(9, i);
            }
        }

        return sum; // Final result return karo
    }
};
