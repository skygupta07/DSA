/*
You have n coins and you want to build a staircase with these coins. The staircase
consists of k rows
where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int count = 0;
        while(n-i > 0){
            i++;
            count++;
            n-=i;
        }
        if (n>0) return count + 1;
        else return count;
    }
};



// -------       -------

class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 1, hi = n;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum == n) {
                return mid;
            } else if (sum < n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};