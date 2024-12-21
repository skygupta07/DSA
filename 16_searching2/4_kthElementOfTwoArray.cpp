#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector <int> c;
        for (auto el: a) c.push_back(el);
        for (auto el: b) c.push_back(el);
        sort(c.begin(), c.end());
        return c[k-1];
    }
};



/*
create vector c -> push elements of both vector a and b
sort vector c 
return c[k-1]

*/


// ----------


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int idx) {
        int m = a.size();
        int n = b.size();
        vector <int> c(m + n , 0);
        

        int i = 0;
        int j = 0;
        int k = 0;
        
        while (i <= m-1 && j <= n-1){
            if (a[i] < b[j]){
                c[k++] = a[i++]; 
            }
            else c[k++] = b[j++];
        }
        
        while (i <= m-1){   // b vector finished
            c[k++] = a[i++];
        }
        
        while (j <= n-1){
            c[k++] = b[j++];
        }
        
        //now return c[idx-1]
        
        return c[idx-1];
    }
};

/*
create vector c ->now use merge sort to merge vector a and vector b ...
then return c[idx-1]

*/


// using binary search  



// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(); // Size of array `a`
        int n = b.size(); // Size of array `b`
        
        // Ensure `a` is the smaller array to perform binary search on it
        if (m > n) return kthElement(b, a, k);
        
        // Binary search range for partitioning `a`
        int lo = max(0, k - n); // Minimum elements taken from `a`
        int hi = min(k, m);     // Maximum elements taken from `a`
        
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // Partition index for `a`
            int j = k - i;              // Partition index for `b`
            
            // Boundary values for partitioning
            int aLeft = (i == 0) ? INT_MIN : a[i - 1]; // Left partition of `a`
            int aRight = (i == m) ? INT_MAX : a[i];   // Right partition of `a`
            
            int bLeft = (j == 0) ? INT_MIN : b[j - 1]; // Left partition of `b`
            int bRight = (j == n) ? INT_MAX : b[j];   // Right partition of `b`
            
            // Check if the partitions are valid
            if (aLeft <= bRight && bLeft <= aRight) {
                // The k-th element is the largest element in the left partitions
                return max(aLeft, bLeft);
            }
            
            // If `aLeft` is too large, move partition `i` to the left
            else if (aLeft > bRight) {
                hi = i - 1;
            }
            
            // If `bLeft` is too large, move partition `i` to the right
            else {
                lo = i + 1;
            }
        }
        
        // Return -1 in case of invalid input or no result (shouldn't happen in valid inputs)
        return -1;
    }
};
        
/*
a vector ko smallest manenge...and agar nahi h to swap kar denge function 
call ko...

*/


