#include <bits/stdc++.h>
using namespace std;

/*

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present at the 
indices ranging from li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].


Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
 

Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length

*/




class Solution {
public:
    // check if start and end with vowel
    
    bool isValid(string str){
        int l = str[0];
        int r = str[str.length() - 1];

        return (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
                 && (r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u');
    }


    vector <int> vowelStrings(vector<string>& words, vector <vector <int>> &queries) {
        int n = words.size();

        vector <int> prefix(n, 0);

        vector <int> ans;

        prefix[0] = (isValid(words[0])) ? 1 : 0;

        for (int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + ( (isValid(words[i])) ? 1 : 0);
        }

        for (auto query : queries){
            int l = query[0];
            int r = query[1];

            if (l == 0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r] - prefix[l-1]);
        }

        return ans;
    }
};


/*

prefixCount of the number of words starting and ending with vowel till here...

*/