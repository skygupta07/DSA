class Solution {
public:
    typedef long long ll;

    bool isPerfectSquare(int n) {
        ll lo = 0;
        ll hi = n;

        while(lo <= hi){
            ll mid = lo + (hi-lo)/2;
            ll square = mid*mid;

            if (square == n) return true;
            else if (square < n){
                lo = mid+1;
            }
            else hi = mid - 1;
        }
        return false;
    }
};