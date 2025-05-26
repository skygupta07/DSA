#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to generate a unique hash for each string based on character frequencies
    string Hash(string &s){
        string hash; // Final hash string
        vector<int> freq(26, 0); // Frequency array for 26 lowercase English letters
        
        // Count the frequency of each character in the string
        for(char ch: s){
            freq[ch - 'a'] += 1; // 'a' se offset nikal kar us character ka index milta hai
        }
        
        // Append each frequency to the hash string with a separator (#)
        for(int i = 0; i < 26; i++){
            hash.append(to_string(freq[i])); // Frequency ko string mein convert karo
            hash.append("#"); // Separator add karo to distinguish between characters
        }
        
        return hash; // Return the hash string
    }

    // Function to group all anagrams together
    vector<vector<string>> anagrams(vector<string>& arr){
        vector<vector<string>> ans; // Result container for groups of anagrams
        unordered_map<string, int> mp; // Map to store hash string and its index in ans
        
        // Iterate over each string in the array
        for(int i = 0; i < arr.size(); i++){
            string key = Hash(arr[i]); // Generate hash for the current string
            
            // Check if this hash is already present in the map
            if(mp.find(key) == mp.end()){
                // Agar hash nahi mila, naya group banate hain
                mp[key] = ans.size(); // Map mein hash ka index store karo
                ans.push_back({}); // Create a new group in the result
            }
            
            // Add the current string to its corresponding group
            ans[mp[key]].push_back(arr[i]);
        }
        
        return ans; // Return the grouped anagrams
    }
};

