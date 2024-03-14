class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            long long m = (long long)mid; // typecasting and poh(principle of homogenity)
            long long y = (long long)x;
            if(m*m == y) return mid; // square nikal raha hai to square nikal bhi to...
            else if(m*m<y) lo = mid+1;
            else hi = mid-1;
        }
        return hi;  // in case number is not perfect square 
    }
};

// binary search mai hamesha main role mid aur target element ka hi hota hai....
// so we also modified them also...