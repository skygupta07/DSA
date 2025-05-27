#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // dono ko sort karke compare karne pe equal aaata hai to 
         // return true else false
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;
        else return false;

    }
};

// --------------------

class Solution {
public:
    bool isAnagram(string s, string t){
        int m = s.size();
        int n = t.size();

        unordered_map <char,int> mp;

        for (int i=0; i<m; i++){
            mp[s[i]]++;
        }

        for (int j=0; j<n; j++){
            mp[t[j]]--;
        }

        // ab sabki frequency genuinely zero honi chahiye...
        for (auto x: mp){
            if (x.second != 0) return false;
        }
        return true;

    }
};



// m1 -> sort and compare

// m2-> This approach counts the frequency of characters in one string and then adjusts the count by decrementing for the other string.
// if finally map contains all non zero element then return true else return false...
// s ne map mai frequency badhayi and t ne ghatayi agar last mai sab badh kam hoke zero ho gya to return true;