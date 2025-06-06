#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set <int> badIndexes;
        stack <int> st;

        for (int i=0; i<s.length(); i++){
            // push opening bracket
            if (s[i] == '(') st.push(i);
            // pop closing bracket iff stack top is opening bracket....else mark the culprit index...
            else if (s[i] == ')'){
                if (st.empty()) badIndexes.insert(i);
                else st.pop();
            }
        }

        // since now our string has been exhausted and still the stack is containing some more opening 
        // brackets => they are also the culprit brackets.... push their index as well...

        while (!st.empty()){
            badIndexes.insert(st.top());
            st.pop();
        }

        string ans = "";

        for (int i=0; i<s.length(); i++){
            if (!badIndexes.contains(i)) ans.push_back(s[i]);   // very grammatical line    

            // because legends do the O(1) operation for push_back....
        }

        return ans;

    }
};

// time -> O(3n)
// space -> O(2n)
/*
for paranthesis problem -> stack should hit your mind first....
for the closing paranthesis -> i look for his corresponding partner (opening paranthesis) in the stack itself..

to maintain the culprit paranthesis ..... we need a data structure...
when i know that I am going to push open paranthesis only in the stack... then more smarter option is pushing 
directly the index into the stack itself....

*/


// --------- method 2 -----

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set <int> badIndexes;
        int diff = 0;

        for (int i=0; i<s.length(); i++){
            if (s[i] == '(') diff++;
            else if (s[i] == ')'){
                if (diff == 0) badIndexes.insert(i);
                else diff--;
            }
        }

        // start iterating from the back..

        for (int i=s.length()-1; i>=0 && diff>0; i--){
            if (s[i] == '('){
                diff--;
                badIndexes.insert(i);
            }
        }

        string ans = "";

        for (int i=0; i<s.length(); i++){
            if (!badIndexes.contains(i)) ans.push_back(s[i]);
        }

        return ans;
    }
};

/*
what about the case I want to do it O(1) space then I will use the diff variable ...
and if in last diff is not zero then diff contains the number of opening brackets as culprit ... and i'm sure that
culprit opening bracket comes in the end of the string....so start iteration from the end and now mark the culprit nodes...



*/



