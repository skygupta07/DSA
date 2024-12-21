#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_set <char> st;

        int maxi = 0;

        int left = 0;

        for (int right=0; right<n; right++){

            if (st.count(s[right])){
                while(st.count(s[right])){
                    st.erase(s[left]);
                    left++; 
                }
                st.insert(s[right]);
            }
            else{
                st.insert(s[right]);
                maxi = max(maxi, right - left + 1);
            }
        }

        return maxi;
    }
};



/*
using set and two pointers... left and right

right pointer ki madad se aage aage string mai iterate karte chalenge....

ek set maintain kara and while encountering a character first we check whether this character 
is already present in the set or not ... if already present means the current character is 
repetitive ... so first erase elements from the left and increment the left pointer also...

but if the character is not already present then simply insert it into the set... 
and wo global maxi (maxLength) ko to maximize karte hi rehna h...



*/




// using unordered_map 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;

        unordered_map <char,int> mp;

        int left = 0;

        for (int right=0; right<n; right++){
            if (mp.count(s[right]) == 0 || mp[s[right] < left]){
                mp[s[right]] = right;
                maxi = max(maxi, right - left + 1);
            }
            else{
                left = mp[s[right]] + 1;    // jump
                mp[s[right]] = right;
            }
        }

        return maxi;
    }
};

/*
The map stores characters as keys and their indices as values.

long jumps happening here..



*/



// using charIndex array

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;

        vector <int> charIndex(128, -1);
        int left = 0;
        
        for (int right=0; right<n; right++){
            if (charIndex[s[right]] >= left) left = charIndex[s[right]] + 1;
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
