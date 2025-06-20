// camelCasePatternMatching.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a dictionary of words arr[] where each word follows CamelCase notation, 
print all words in the dictionary that match with a given pattern pat 
consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases 
such that each word or abbreviation begins with a capital letter. 

Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

Example: "GeeksForGeeks" matches the pattern "GFG", 
because if we combine all the capital letters in "GeeksForGeeks" they become "GFG". 
Also note "GeeksForGeeks" matches with the pattern "GFG" and also "GF", but does not match with "FG".

Note: The driver code will sort your answer before checking and return the answer in any order.

Examples:

Input: arr[] = ["WelcomeGeek", "WelcomeToGeeksForGeeks", "GeeksForGeeks"], pat = "WTG"
Output: ["WelcomeToGeeksForGeeks"]

Explanation: Since only "WelcomeToGeeksForGeeks" matches the pattern, it is the only answer.
Input: arr[] = ["Hi", "Hello", "HelloWorld", "HiTech", "HiGeek", 
"HiTechWorld", "HiTechCity", "HiTechLab"], pat = "HA"

Output: []
Explanation: None of the words matches the given pattern.


Constraints:
1 <= arr.size() <= 1000
1 <= pat.size() <= 100
1 <= arr[i].size() <= 100

*/


class Solution {
public:
    
    vector <string> camelCase(vector <string> &arr, string &pat) {
        vector <string> ans;
        
        // array ki har string pe gaye..
        for (auto str : arr){
            string temp = "";
            
            // har string ke then har character pe gaye...
            for (auto ch : str){
                if (isupper(ch)) temp += ch;
                
                // as soon as temp equals pat then store this str... jaise GFG match ho gya sahi h... 
                // aage aur GFGLE jaisa bhi kucch hota to koi baat nahi .. ye included hoga answer mai..
                
                if (temp == pat) {
                    ans.push_back(str);
                    break;
                }

            }
        }

        return ans;
    }

};


/*

go to each string 

    then in each string store all the uppercase character in serial order...
    at every moment if the stored uppercase letter string becomes equal to the 
    pattern then store it in answer....
    
    return ans;

*/

