#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).

*/

class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.length();
        int i = 0;
        int j = n-1;

        // first check ith and jth char same then try to inc size of prefix and suffix
        
       while (i<j){

            if (s[i] == s[j]){
                // increasing prefix size
                while (s[i] == s[i+1] && i<j){
                    i++;    
                }
                // i = 1

                while (s[j] == s[j-1] && i<j){      // dono mai i<j ki condition lagai taaki intersection se bach sake...
                    j--;
                }
                // j = 8
            }
            else{
                break;
            }

            i++;    // for next iteration....
            j--;
       }

       int count = 0;

       for (int it = i; it<=j ; it++){
           count++;
       }
       return count;
        
    }
};

// delete both the prefix and suffix -> two pointer approach...
// accha mera 99th case mai bbbbbbbbbbb wale case mai prefix and suffix might intersect.....