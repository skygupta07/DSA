#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;

        // hashset mai aapka count method ...massallah 

        unordered_set <char> charSet;
        int left = 0;

        for (int right=0; right<n; right++){

            if (charSet.count(s[right]) == 0){  // unique element found => insert it and update maxLength.....
                charSet.insert(s[right]);
                maxLength = max(maxLength, right-left + 1);
            }
            
            else{   // yani ki repeted element hai.... to pehle left pointer ko sahi jagah leke aao..
            // i.e. left se bando ko hatate jao...
                while (charSet.count(s[right])){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};


/*
two pointer left right use kiya ....
aur hashset mai store kara element ....taki pata chal jaye ki abhi substring 
mai koi repeted to nahi aa raha ...
*/



