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

// binary search mai jab bhi loop break hota hai.. hi aapka lower bound pe hota hai..
// and lo aapka upper bound pe hota hai.....



// -------- ----------

class Solution {
public:
    int mySqrt(int x){
        if (x==0 || x==1) return x;
        long long lo = 0;
        long long hi = x;
        while (lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if (mid*mid == x) return mid;
            else if (mid*mid < x) lo = mid+1;
            else hi = mid-1;
        }
        return hi;  // if the number is not perfect square then lower bound return karwaya.
    }
};