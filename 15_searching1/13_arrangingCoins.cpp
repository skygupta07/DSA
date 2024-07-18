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