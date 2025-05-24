#include <bits/stdc++.h>
using namespace std;

/*

You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. 
Apply the following algorithm on arr:

Starting from left to right, remove the first number and every other number afterward until you 
reach the end of the list.
Repeat the previous step again, but this time from right to left, 
remove the rightmost number and every other number from the remaining numbers.

Keep repeating the steps again, alternating left to right and right to left, 
until a single number remains.
Given the integer n, return the last number that remains in arr.


Example 1:

Input: n = 9
Output: 6
Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]

Example 2:

Input: n = 1
Output: 1

*/

class Solution {
public:
        int lastRemaining(int n) {
            if (n == 1) return 1;
            return 2 * (n/2 + 1 - lastRemaining(n / 2));
        }
};


class Solution {
    public:
        int lastRemaining(int n) {
            int head = 1;      // Yeh current first element hai jo list mein bacha hai
            int step = 1;      // Har round ke baad distance between elements badhta hai (2x hota hai)
            bool left = true;  // Direction: pehle left to right jaayenge
    
            // Jab tak ek hi element nahi bacha hota
            while (n > 1) {
                
                // Agar left to right ja rahe hai ya n even hai, toh head update hoga
                if (left || n % 2 == 1) {
                    head += step; // Head ko step se aage badha do
                }
    
                // Ab next round:
                n /= 2;         // Har round ke baad aadhi list eliminate ho jaati hai
                step *= 2;      // Step 2x ho jaata hai kyunki har baar alternate elements bachte hai
                left = !left;   // Direction alternate hoti hai: L->R, then R->L, then again L->R...
            }
    
            return head;  // Jab ek hi element bacha hota hai, wahi answer hota hai
        }
    };
    