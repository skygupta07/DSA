// arrangingCoins

/*

You have n coins and you want to build a staircase with these coins. 
The staircase consists of k rows where the ith row has exactly i coins.
The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.
 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.


Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 2pow31 - 1


*/


// my first approach
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int rowCount = 0;

        // if there are remaining coins
        while(n-i > 0){
            rowCount++;
            
            i++;
            n -= i;
        }

        // if still there are coins left then one more row can be occupied (although it is not necessary
        // that it should be completely full...)

        if (n > 0) return rowCount + 1;

        else return rowCount;
    }
};



// -------       -------

class Solution {
public:

    int arrangeCoins(int n) {
        long long lo = 1, hi = n;

        while (lo <= hi) {
            // let's try ki mid number of steps required ho..
            long long mid = lo + (hi - lo) / 2;
            
            // 1 + 2 + 3 + 4 + .. sumuptoMid   
            long long sum = mid * (mid + 1) / 2;

            if (sum == n) return mid;
            
            // try higher...
            else if (sum < n) lo = mid + 1;
            
            // try lesser...
            else hi = mid - 1;
        }

        return hi; // finally return lower bound as there will be only hi number of complete rows only...
    }

};