#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string makeFancyString(string s) {
        // create the string ...
        string ans = "";
        ans.push_back(s[0]);    // threshold...

        int n = s.size();
        int cnt = 1;    // ek khud ko to ginega...

        for(int i=1;i<n;i++){
            if(s[i] == ans.back()){ // ha string ka back bhi hota h.. jaise vector ka back hota h,,
                cnt++;
                if(cnt < 3) ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};