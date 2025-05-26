#include <bits/stdc++.h>
using namespace std;

/*

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. 
Sort the words with the same frequency by their lexicographical order.
 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.


Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> ans;
        
        map <string, int> mp; // string , freq
    
        for (auto word : words) mp[word]++;

        
        auto cmp = [](const pair <int, string> &a, const pair <int, string> &b){
            // Higher frequency comes first; if frequencies are equal, lexicographical order applies
            return (a.first < b.first || (a.first == b.first && a.second > b.second));
        };


        priority_queue <pair <int, string>, vector <pair <int, string>> , decltype(cmp) > pq(cmp); // freq, string

        for (auto el : mp){
            pq.push({el.second, el.first});
        }

        while (!pq.empty() && k-- ){
            string temp = pq.top().second;
            pq.pop();

            ans.push_back(temp);
        }
        
        return ans;
    }
};

/*
map to store words and frequency
then maxheap to store freq, and word 
fetch k most frequent words.. (words with same frequency should follow lexographical order)

*/