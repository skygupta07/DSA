// checkIfTheSentenceIsPangram.cpp


/*


A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, 
return true if sentence is a pangram, or false otherwise.


Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.


Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;


bool ninjaGram(string &s){   
    unordered_set <char> st;
    
    for (int i=0; i<s.length(); i++){
        if(isalpha(s[i])){
            st.insert(tolower(s[i]));
        }
    }

    return (st.size() == 26);
}
