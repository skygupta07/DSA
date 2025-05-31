#include <bits/stdc++.h>
using namespace std;

/*

Given two {sorted arrays}** kaan khade ho gaye..., a[] and b[] and an element k, 
the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10].
The 5th element of this array is 6.


Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. 
The 7th element of this array is 256.


Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108

*/



/*
create vector c -> push elements of both vector a and b
sort vector c 
return c[k-1]

*/

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




class Solution {
  public:
    int kthElement(vector <int> &a, vector <int> &b, int idx) {
        int m = a.size();
        int n = b.size();
        
        vector <int> c(m + n , 0);

        int i = 0;
        int j = 0;
        int k = 0;
        
        while (i <= m-1 && j <= n-1){  // or simply i < m && j < n
            if (a[i] < b[j]){
                c[k++] = a[i++]; 
            }
            else c[k++] = b[j++];
        }

        // b vector finished
        while (i <= m-1) c[k++] = a[i++];
        
        // a vector finished - matlab b vector ke elements ab phir aage laga do..
        while (j <= n-1) c[k++] = b[j++];
        
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
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int m = a.size(); 
        int n = b.size(); 
        
        // Intuition: Binary search karne ke liye hamesha chhoti array pe karna behtar hota hai
        // Kyuki fir humara search space chhota hoga -> Faster binary search
        
        if (m > n) return kthElement(b, a, k); // agar a badi hai, to swap karke chhoti ko pehle pass karo

        // Ab binary search karenge 'a' par (jo chhoti hai)
        int lo = max(0, k - n);  // kam se kam itne elements 'a' se le sakte hai
        int hi = min(k, m);      // zyada se zyada itne elements 'a' se le sakte hai

        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // a me kitne elements lenge
            int j = k - i;              // b me automatically bachhe hue lenge (k total chahiye hume)

            // Boundary conditions check (agar i ya j zero ya size tak pahuch jaye)
            int aLeft = (i == 0) ? INT_MIN : a[i - 1];     // a ke left part ka last element
            int aRight = (i == m) ? INT_MAX : a[i];        // a ke right part ka first element

            int bLeft = (j == 0) ? INT_MIN : b[j - 1];     // b ke left part ka last element
            int bRight = (j == n) ? INT_MAX : b[j];        // b ke right part ka first element

            // Valid partition tabhi hoga jab left side ke max <= right side ke min ho
            if (aLeft <= bRight && bLeft <= aRight) {
                // K-th smallest element hamesha left half ka maximum hoga
                return max(aLeft, bLeft);
            } 
            // agar a ka left bada hai b ke right se, to i ko left le jao
            else if (aLeft > bRight) {
                hi = i - 1;
            } 
            // agar b ka left bada hai a ke right se, to i ko right le jao
            else {
                lo = i + 1;
            }
        }

        // Ideally kabhi yahan nahi aana chahiye (input valid ho to)
        return -1;
    }
};
