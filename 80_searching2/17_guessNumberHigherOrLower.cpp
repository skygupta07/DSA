#include <bits/stdc++.h>
using namespace std;


/*

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1


*/


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
    public:
        int guessNumber(int n) {
            int lo = 1;
            int hi = n;
    
            while (lo <= hi){
                int mid = lo + (hi - lo)/2;
    
                int guessNum = guess(mid);
    
                if (guessNum == 0) return mid;
    
                else if (guessNum == -1) hi = mid - 1;
                else lo = mid + 1;
            }
            return -1;
        }
    };