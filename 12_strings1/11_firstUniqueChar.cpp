#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s){

        vector <int> v(26,0);
        for (int i=0; i<s.length(); i++){
            char ch = s[i];
            v[ch - 'a']++;
        }
        
        for (int i=0; i<s.length(); i++){
            if (v[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

/*
smart use of ascii value
index find karne ka casual tarika is char - 'a'
// next loop mai vector mai bhi to corresponding mapping dekhni hogi...

*/

