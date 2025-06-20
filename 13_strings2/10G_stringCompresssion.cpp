// stringCompression3.cpp

/*

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:

Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.

Return the string comp.

Example 1:

Input: word = "abcde"
Output: "1a1b1c1d1e"


Explanation:
Initially, comp = "". Apply the operation 5 times, 
choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.


Example 2:

Input: word = "aaaaaaaaaaaaaabb"
Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, 
choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.

Constraints:

1 <= word.length <= 2 * 1e5
word consists only of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string compressedString(string word) {
        string ans = "";

        int n = word.length();
        int count = 1;


        for (int i=1; i<n; i++){

            // count consecutive same characters streak
            if (word[i] == word[i-1]){
                count++;
            }

            // if streak breaked by word[i] matlab word[i-1] tak streak bani thi...
            else{  

                while (count > 0){
                    int chunk = min(9, count);
                    
                    ans += to_string(chunk) + word[i-1];
                    count -= chunk;
                }
                
                count = 1;  // reset count to 1 again for next upcoming characters...
            
            }

        }

        // there will be no one to break the streak of last consecutive element so do it again for him..

        while (count > 0){
            int chunk = min(9, count);

            ans += to_string(chunk) + word[n-1];
            count -= chunk;
        }
        
        return ans;
    }
};


/*

count = 1 maan ke chala ...
i = 1 se start kara.... 


jab tak streak ban rahi hai maintain karo....
and jaise hi streak break kare ...koi character to count karna start kar do chunks and start 
making the answer string as well...

*/