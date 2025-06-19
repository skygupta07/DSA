// reverseWordsInAString.cpp

#include <bits/stdc++.h>
using namespace std;


/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.
 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

*/


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;

        stack <string> stk;

        while (i < n){

            // skipping any leading spaces
            while ( i<n && s[i] == ' ') i++;

            string word = "";
            while (i<n && s[i] != ' '){
                word += s[i];
                i++;
            }

            // if a word was formed , push it to the stack..
            if (!word.empty()){
                stk.push(word);
            }

        }

        string ans = "";
        
        // best way to Ensure to avoid appending an extra space at the end.
        while (!stk.empty()){

            ans += stk.top();
            stk.pop();

            if (!stk.empty()){
                ans += " ";
            }
        }

        return ans;

    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();


/*
string par iterate karta hu... spaces ko ignore karna hai jab bhi aaye...
aur jaise hi ek word ban jaata hai ...usko stack mai push kar do....

then stack se word nikal ke word form karna hai....


*/


class Solution {
    private:

        void reverse(string &s, int i, int j){  // by reference
            
            while(i < j){
              
              char temp = s[i];
              s[i] = s[j];
              s[j] = temp;

              i++;
              j--;
            } 

        }

    public:

        string reverseWords(string &s) {
            int i=0, j=0;   // i will start from starting 
                            // j will go ahead skipping the characters and will find the new character...
            int l = 0;

            int len = s.length();

            int wordcount = 0;

            while(true){

                // skip the space characters.....
                while(i <= len-1 && s[i] == ' ') i++;

                if(i == len) break;   // if i crossed the string then break ...
                // basically this will stop the outer while looop condition...

                // agar koi word ban gaya hai to uske aage space lagaya...aur j ko increase bhi kiya..
                if(wordcount) s[j++]=' ';   

                l = j;

                while(i < len && s[i] != ' '){    // when you have encountered a char then ab to word banao...
                    s[j] = s[i];

                    i++;
                    j++;
                }
                
                reverse(s,l,j-1);   // reverse the just form word...             
                
                wordcount++;   
            }

            s.resize(j);   

            reverse(s,0,j-1);   // reverse the whole string....

            return s;        
        }
    };
    
    // puri string ko reverse karne ke liye...pehle har word ko reverse kiya 
    // then whole string ko reverse kar diya.
    
    // creating vector of string and push back the words in it...
    // now reverse the vector.....
    // remove extra blank spaces....
    // how to trace that a word has started...and has ended and another word has started again...
    
    