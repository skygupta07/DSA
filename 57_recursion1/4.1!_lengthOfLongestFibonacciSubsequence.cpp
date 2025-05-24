// lengthOfLongestFibonacciSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*

A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n

Given a strictly increasing array arr of positive integers forming a sequence, 
return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none)
from arr, without changing the order of the remaining elements. 
For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].


Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
 

Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109

*/


class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();  
            unordered_set<int> st; // Set use kar rahe hain taaki elements ko fast access kar sakein.
    
            // Sare elements ko set me store kar rahe hain taaki O(1) me check kar sakein.
            for (auto el : arr) st.insert(el);
    
            int count = 0;  // Har Fibonacci subsequence ka count track karne ke liye.
            int maxi = INT_MIN; // Maximum length store karne ke liye.
    
            // First element choose karne ke liye loop
            for (int i = 0; i < n; i++) {
                // Second element choose karne ke liye loop
                for (int j = i + 1; j < n; j++) {
                    
                    int a = arr[i]; // Pehla element
                    int b = arr[j]; // Dusra element
    
                    int c = a + b;  // Teesra element jo Fibonacci condition satisfy karega.
    
                    count = 2; // Minimum Fibonacci subsequence length 2 hoti hai.
    
                    // Jab tak next Fibonacci number set me mil raha hai, sequence ko extend karte raho.
                    while (st.find(c) != st.end()) {
                        count++; // Sequence length badhao
                        a = b;   // Pichle do elements update karo
                        b = c;
    
                        c = a + b; // Naya Fibonacci number generate karo
                    }
    
                    // Maximum subsequence length ko update karo
                    maxi = max(maxi, count);
                }
            }
    
            // Agar koi valid Fibonacci subsequence mila, toh return karo warna 0.
            return maxi > 2 ? maxi : 0;
        }
    };
    