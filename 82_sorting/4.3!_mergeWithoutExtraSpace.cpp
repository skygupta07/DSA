// mergeWithoutExtraSpace.cpp

/*

Given two sorted arrays a[] and b[] of size n and m respectively, 
the task is to merge them in sorted order without using any extra space. 
Modify a[] so that it contains the first n elements and modify b[] 
so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output: a[] = [2, 2, 3, 4], b[] = [7, 10]

Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]

Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output: a[] = [1, 2, 3, 5, 8, 9], b[] = [10, 13, 15, 20]
Explanation: After merging two sorted arrays we get [1, 2, 3, 5, 8, 9, 10, 13, 15, 20].


Input: a[] = [0, 1], b[] = [2, 3]
Output: a[] = [0, 1], b[] = [2, 3]
Explanation: After merging two sorted arrays we get [0, 1, 2, 3].

Constraints:
1 ≤ n, m ≤ 1e5
0 ≤ a[i], b[i] ≤ 1e7

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        vector <int> c;
        
        for (auto el: a) c.push_back(el);
        for (auto el: b) c.push_back(el);
        
        sort(c.begin(), c.end());
        
        for (int i=0; i<n; i++){
            a[i] = c[i];
        }
        
        int idx = 0;
        for (int j=n; j<n+m; j++){
            b[idx++] = c[j];
        }
        
        return;
    }
    
};



class Solution {
public:

     int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap + 1) / 2;
    }


    void mergeArrays(vector <int> &a, vector <int> &b) {
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





