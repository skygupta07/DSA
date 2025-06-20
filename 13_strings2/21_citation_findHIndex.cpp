// findHIndex.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers citations where citations[i] is the number of citations 
a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as 
the maximum value of h such that the given researcher has published at least h papers 
that have each been cited at least h times.
 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3

Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 
3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two 
with no more than 3 citations each, their h-index is 3.


Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

*/

class Solution {
public:

    // Function to find the H-index from the citation array
    int hIndex(vector <int> &citations) {
        int n = citations.size(); // total number of papers

        // Step 1: Sort the citations in ascending order
        // Taki hum har ek paper ke liye dekh saken ki uske aage kitne papers bache hain
        sort(citations.begin(), citations.end());

        int hIndex = 0; // Initialize the answer

        // Step 2: Traverse the sorted citations
        for (int i = 0; i < n; i++) {

            // hCandidate = remaining papers including this one → n - i
            // kyunki index i tak ke (0 to i-1) paper already check ho chuke hain
            int hCandidate = n - i;

            // Step 3: Check if current paper citation is ≥ remaining papers count
            // matlab: kya hCandidate papers hain jinke paas ≥ hCandidate citations hain?
            if (citations[i] >= hCandidate) {
                
                // Yes! Toh yehi h-index ban sakta hai
                hIndex = hCandidate;

                // kyunki hIndex is maximum possible h, and we are going from left to right
                // toh pehla match hi best match hoga
                break;
            }
        }

        // Step 4: Return the final h-index
        return hIndex;
    }
};


/*

Agar hum citations ko sort kar dein (ascending), toh har index i par n - i papers baaki rahenge.
Toh agar citations[i] >= (n - i), matlab kam se kam (n - i) papers hain jinke paas 
(n - i) ya usse zyada citations hain — which is a valid h-index candidate.

*/