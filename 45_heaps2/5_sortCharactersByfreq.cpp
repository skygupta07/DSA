#include <bits/stdc++.h>
using namespace std;



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
            result.append( p.second, p.first );
        }

        return result;

        
    }
};


------------

#define pp pair <int, char>


class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> mp;

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