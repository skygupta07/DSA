// topKFrequentWords.cpp

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
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, 
with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/

class Solution {
public:
    vector <string> topKFrequent(vector<string>& words, int k) {
        vector <string> ans;
        map <string, int> mp; // Map to store words and their frequencies

        // Count the frequency of each word
        for (auto word : words) {
            mp[word]++;
        }

        // Custom comparator for the priority queue
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            // Higher frequency comes first; if frequencies are equal, lexicographical order applies
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
        };

        // Max heap (priority queue) with custom comparator
        priority_queue <pair <int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        // Push all elements from the map into the priority queue
        for (auto el : mp) {
            pq.push({el.second, el.first});
        }

        // Fetch the top K most frequent words
        while (!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
