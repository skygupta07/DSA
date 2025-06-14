// letterTilePossibilities.cpp


#include <bits/stdc++.h>
using namespace std;

/*

You have n tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters 
printed on those tiles. 


Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".


Example 2:

Input: tiles = "AAABBC"
Output: 188


Example 3:

Input: tiles = "V"
Output: 1
 
Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/

class Solution { 
    public:
        int numTilePossibilities(string tiles) {
            int n = tiles.length(); // Total length store kar liya
    
            vector <int> counts(26, 0);  // Har letter ('A' - 'Z') ki frequency count karne ke liye
            vector <int> fact(n + 1, 1); // Factorials store karenge taaki baar-baar calculate na karna pade
    
            // Factorial precompute kar rahe hain taaki fast computation ho
            for (int i = 1; i <= n; i++) {
                fact[i] = i * fact[i - 1];  
            }
    
            // Har character ka count nikal liya - ye sahi chalaki kari jab capital letter ki frequency 
            // store karni thi to sach mai hi capital hi letter subtract kar diya...
            for (char ch : tiles) counts[ch - 'A']++; 
    
            // lengthcounts[i] → store karega total unique sequences of length `i`
            vector <int> lengthcounts(n + 1, 0);
            lengthcounts[0] = 1; // Empty sequence ka ek count maan liya
    
            // 26 letters ko check kar rahe hain
            for (int i = 0; i < 26; i++){

                if (counts[i] > 0) {  // Agar ye letter tiles mein present hai
                    vector <int> temp(n + 1, 0); // Temporary store karne ke liye
    
                    // Pehle se jo lengths possible hain, unke liye naye subsequences banayenge
                    for (int j = 0; j <= n && lengthcounts[j] > 0; j++) {
    
                        // Is character ke liye 1 se max count tak naye subsequences create karenge
                        for (int k = 1; k <= counts[i]; k++) {
                            int totallength = j + k; // Naya sequence ka length
    
                            // Permutation formula lagaya: (j+k)! / (k! * j!)
                            temp[totallength] += lengthcounts[j] * fact[totallength] / (fact[k] * fact[j]);
                        }
                    }
    
                    // temp array ko final lengthcounts mein merge kar diya
                    for (int j = 0; j <= n; j++) {
                        lengthcounts[j] += temp[j];
                    }
                }
            }
    
            // Final answer calculate kar rahe hain (length 1 se n tak ka sum)
            int ans = 0;
            
            for (int i = 1; i <= n; i++) {
                ans += lengthcounts[i];
            }
            
            return ans;
        }
    };
    