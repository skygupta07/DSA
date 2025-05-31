// firstBadVersion.cpp

#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int lo = 1;   // min Bad version possible
        long long int hi = n;   // max Bad version possible

        long long int minBadVersion;    // to store answer # important

        while (lo <= hi){
            long long int mid = lo + (hi - lo)/2;

            if (isBadVersion(mid) == 1){
                minBadVersion = mid;    // store this version as bad version
                hi = mid - 1;   // try for more earlier bad version (smaller number)
            }
            else{
                lo = mid + 1;
            }
        }

        return minBadVersion;
    }
};