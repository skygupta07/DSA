// sortCharactersByFrequency.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, sort it in decreasing order (bada pehle) based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.


Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.


*/



class Solution {
public:
    string frequencySort(string s){
        // custom comparator for comparing on basis of frequency...
        auto cmp = [] (const pair <char, int> &a, const pair <char,int> &b){
            return a.second < b.second;
        };

        priority_queue <pair <char,int>, vector<pair <char,int>>, decltype(cmp) > pq(cmp);

        unordered_map <char,int> mp;

        for (char c : s) mp[c]++;

        for (const auto &entry : mp){
            pq.push( make_pair (entry.first, entry.second) );
        }

        string result = ""; // declare empty string....

        while (!pq.empty()){
            pair <char,int> p = pq.top();
            pq.pop();
            result.append( p.second, p.first ); // append p.second times p.first to result
        }

        return result;

        
    }
};


#define pp pair <int, char>


class Solution {
public:

    string frequencySort(string s) {

        unordered_map <char,int> mp; // freqMap

        // storing freq of char
        for (auto ch : s){
            mp[ch]++;
        }

        priority_queue <pp> pq;
        
        for (auto entry : mp){
            char key = entry.first;
            int val = entry.second;

            pq.push({val, key});
        }

        string result = "";

        while (!pq.empty()){
            
            // to po push
            pp curr = pq.top();
            pq.pop();

            for (int i=0; i<curr.first; i++){
                result += curr.second;
            }

        }
        return result;
    }
};