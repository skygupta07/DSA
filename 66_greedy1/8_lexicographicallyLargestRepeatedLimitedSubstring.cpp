//lc 2182. Construct String With Repeat Limit

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        // Step 2: Use a max-heap (priority queue) to store characters and their frequencies
        priority_queue<pair<char, int>> pq;
        for (auto p : mp) {
            pq.push(p);
        }
        
        string result = "";
        
        // Step 3: Build the result string while respecting the repeatLimit constraint
        while (!pq.empty()) {
            // Get the character with the highest lexicographical order and its frequency
            auto largest = pq.top();
            pq.pop();
            
            // Determine the number of times to add the current character without exceeding repeatLimit
            int len = min(repeatLimit, largest.second);
            for (int i = 0; i < len; i++) {
                result += largest.first;
            }
            
            // If the current character has more occurrences left after the current batch
            if (largest.second - len > 0) {
                // If the priority queue is not empty, get the next largest character
                if (!pq.empty()) {
                    auto secondLargest = pq.top();
                    pq.pop();
                    
                    // Add one occurrence of the next largest character to the result
                    result += secondLargest.first;
                    
                    // If the second largest character still has more occurrences, push it back into the priority queue
                    if (secondLargest.second - 1 > 0) {
                        pq.push({secondLargest.first, secondLargest.second - 1});
                    }
                    
                    // Push the remaining occurrences of the largest character back into the priority queue
                    pq.push({largest.first, largest.second - len});
                } else {
                    // If the priority queue is empty, we can't add more characters, so return the result
                    return result;
                }
            }
        }
        
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    string s = "cczazcc";
    int repeatLimit = 2;
    cout << solution.repeatLimitedString(s, repeatLimit) << endl;
}


/*
first of all try to include max repeat limit of first lexicographically largest 
and then give partition of second lexicographically largest char and 
then again first lexicographically largest then second and so on 
..until first exhaust then second will be in main role and third as partition

so better to use max heap with pair <char, freq>  and then repeat the process for freq - k 

// priority queue or map mai se element nikalna easy...simply auto ka use kiya..

for auto p in mp try pq.push(s[i]);

*/














int main(){


}
























/*
lexicographically -> matlab dictionary Order

// lexicographically larger wale element ko place kiya k times then 2nd largest available 
lexicographic element ko singly place kiya then first wala fill kiya repeat until
the very first element exhausts then repeat the process for 2nd largest available element\



\\\\\
\


*/