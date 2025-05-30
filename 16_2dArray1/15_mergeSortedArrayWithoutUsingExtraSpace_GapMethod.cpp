#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

     int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap + 1) / 2;
    }


    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int gap = nextGap(n + m);

        while (gap > 0) {
            int i = 0;

            // Compare elements in the first array
            while (i + gap < n) {
                if (a[i] > a[i + gap]) {
                    swap(a[i], a[i + gap]);
                }
                i++;
            }

            // Compare elements between both arrays
            int j = gap > n ? gap - n : 0;
            while (i < n && j < m) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                }
                i++;
                j++;
            }

            // Compare elements in the second array
            j = 0;
            while (j + gap < m) {
                if (b[j] > b[j + gap]) {
                    swap(b[j], b[j + gap]);
                }
                j++;
            }

            gap = nextGap(gap);
        }
    }
};


