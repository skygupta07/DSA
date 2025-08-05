// maximumNumberOfSubsequencesAfterOneInserting.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given a string s consisting of uppercase English letters.

You are allowed to insert at most one uppercase English letter at any position
(including the beginning or end) of the string.

Return the maximum number of "LCT" subsequences that can be formed in the resulting string
after at most one insertion.


Example 1:

Input: s = "LMCT"
Output: 2

Explanation:

We can insert a "L" at the beginning of the string s to make "LLMCT",
which has 2 subsequences, at indices [0, 3, 4] and [1, 3, 4].

Example 2:

Input: s = "LCCT"
Output: 4

Explanation:

We can insert a "L" at the beginning of the string s to make "LLCCT",
which has 4 subsequences, at indices [0, 2, 4], [0, 3, 4], [1, 2, 4] and [1, 3, 4].

Example 3:

Input: s = "L"

Output: 0

Explanation:

Since it is not possible to obtain the subsequence "LCT" by inserting a single letter,
the result is 0.



Constraints:

1 <= s.length <= 1e5
s consists of uppercase English letters.

*/


class Solution {
public:

    long long numOfSubsequences(string s) {

        int n = s.size();

        // prefixL[i] = number of 'L's in s[0..i-1]
        // prefixLC[i] = number of "LC" subsequences ending before index i

        vector <long long> prefixL(n + 1, 0), prefixLC(n + 1, 0);

        for (int i = 0; i < n; i++) {

            prefixL[i + 1] = prefixL[i];
            prefixLC[i + 1] = prefixLC[i];

            if (s[i] == 'L') prefixL[i + 1]++;

            else if (s[i] == 'C') prefixLC[i + 1] += prefixL[i]; // ✅ Use Ls strictly before current C
        }

        // suffixT[i] = number of 'T's in s[i..n-1]
        // suffixCT[i] = number of "CT" subsequences starting at or after index i
        vector <long long> suffixT(n + 1, 0), suffixCT(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            suffixT[i] = suffixT[i + 1];
            suffixCT[i] = suffixCT[i + 1];

            if (s[i] == 'T') suffixT[i]++;
            
            else if (s[i] == 'C') suffixCT[i] += suffixT[i + 1]; // ✅ Use Ts strictly after current C
        }

        // Base count of "LCT" subsequences without any insertion
        long long base = 0, countL = 0, countLC = 0;

        for (char ch : s) {

            if (ch == 'L') countL++;

            else if (ch == 'C') countLC += countL;

            else if (ch == 'T') base += countLC;
        }

        long long maxGain = 0;

        // Try inserting 'L', 'C', or 'T' at every possible position
        for (int i = 0; i <= n; i++) {

            // Insert 'L' → can form new "LCT" with all CTs after position i
            maxGain = max(maxGain, suffixCT[i]);

            // Insert 'C' → can form new "LCT" with Ls before and Ts after
            maxGain = max(maxGain, prefixL[i] * suffixT[i]);

            // Insert 'T' → can form new "LCT" with all LCs before position i
            maxGain = max(maxGain, prefixLC[i]);

        }

        return base + maxGain;

    }
    
};
