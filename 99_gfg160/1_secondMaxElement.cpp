#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
       int fmax = INT_MIN;
       int smax = INT_MIN;
       
       for (int i=0; i<n; i++) fmax = max(fmax, arr[i]);
       
       for (int i=0; i<n; i++){
           if (arr[i] > smax && arr[i] != fmax) smax = max(smax, arr[i]);
       }
       
       if (smax == INT_MIN || smax == fmax ) return -1;
       return smax;
    }
};


------


// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        unordered_set <int> st(arr.begin(), arr.end());
        
        priority_queue <int> pq(st.begin() , st.end());
        int fmax = pq.top();
        pq.pop();
        int smax = pq.top();
        
        return (smax == fmax) ? -1: smax;
    }
};