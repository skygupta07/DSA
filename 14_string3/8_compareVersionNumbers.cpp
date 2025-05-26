#include <bits/stdc++.h>
using namespace std;

/*

Given two version strings, version1 and version2, compare them. 
A version string consists of revisions separated by dots '.'. 
The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. 
If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.2", version2 = "1.10"
Output: -1

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:

Input: version1 = "1.01", version2 = "1.001"
Output: 0

Explanation:

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".


Example 3:

Input: version1 = "1.0", version2 = "1.0.0.0"
Output: 0

Explanation:

version1 has less revisions, which means every missing revision are treated as "0".

 

Constraints:

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit integer.


*/

class Solution {
public:

    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();

        for (int i=0, j=0; i<n1 || j<n2; i++, j++){
            int x1 = 0;
            int x2 = 0;

            while (i < n1 && version1[i] != '.'){
                x1 = (x1 * 10) + (version1[i++] - '0');
            }

            while (j < n2 && version2[j] != '.'){
                x2 = (x2 * 10) + (version2[j++] - '0');
            }

            if (x1 < x2) return -1;
            else if (x1 > x2) return 1;

            // reset value of x1 x2 for next fresh numbers after decimal..
            x1 = 0;
            x2 = 0;
            
        }

        // abhi tak kam jyada nahi aaye matlab both versions are equal.
        return 0; 
    }
};


/*
jab tak dono string khatam nahi ho jaati tab tak compute karna h..

v1 ke har version release number ko matab dot separated number ko 
har dot ke baad number ko extract kiya and then compare kara...





*/