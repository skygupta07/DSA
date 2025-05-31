#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0;
        int hi = n - 1;

        // Binary search to find the h-index
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // If the citation count at mid is less than (n - mid),
            // it means we need to look at higher indices
            if (citations[mid] < n - mid)
                lo = mid + 1;
            else
                // If citations[mid] is greater than or equal to (n - mid),
                // it means the current position could be a valid h-index or we need to look lower
                hi = mid - 1;
        }

        // hIndex is calculated as the number of papers that have at least 'n - lo' citations
        int hIdx = n - lo;
        return hIdx;
    }
};
