#include <bits/stdc++.h>
using namespace std;

/*

You are given a 0-indexed array words consisting of distinct strings.

The string words[i] can be paired with the string words[j] if:

The string words[i] is equal to the reversed string of words[j].
0 <= i < j < words.length.
Return the maximum number of pairs that can be formed from the array words.

Note that each string can belong in at most one pair.

*/

class solution{
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n = arr.size();
        int count = 0;
        for (int i=0; i<n-1; i++){  // last wala element to already check ho chuka hai
            string rev = arr[i];
            reverse(rev.begin(), rev.end());  // function to reverse a string

            for (int j=i+1; j<n; j++){
                if (rev == arr[j]) count++;
            }
        }
        return count;
    }
};





// -----------------



class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        
        // string wali array me traverse karte hue chalo har word ko reverse karo
         // then check karo agar wo word pehle se arr me nahi hai to daal do 
       // aur agar pehle se hai to count increment kar do then return count

       unordered_set <string> s; 
       int n = arr.size();
       int count = 0;
       for (int i=0; i<n; i++){
           string rev = arr[i];  // ek tarah se rev me uski copy store kari now reverse karunga 
           reverse(rev.begin() , rev.end());

           // set me find karo reverse word ko
           if(s.find(rev)!=s.end()) count++;
           else s.insert(arr[i]); 

       }
       return count;
    }
};


