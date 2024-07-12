#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // Create an unordered map to track the count of groups of rabbits with the same color
        unordered_map<int, int> mp;
        int result = 0;  // Initialize the result to store the minimum number of rabbits

        // Iterate through each rabbit's answer
        for (int i = 0; i < answers.size(); i++) {
            // If there is no group that matches the current rabbit's answer + 1
            if (!mp[answers[i] + 1]) {
                result += answers[i] + 1;  // Add a new group of size answers[i] + 1 to the result
                if (answers[i] == 0) continue;  // If the answer is 0, no more rabbits in this group
                mp[answers[i] + 1] = 1;  // Initialize the count for this group size in the map
            }
            else {
                // If there is already a group that matches the current rabbit's answer + 1
                mp[answers[i] + 1]++;  // Increment the count for this group size
                int key = answers[i] + 1;
                int val = mp[key];
                if (key == val) {  // If the group is complete (key == val)
                    mp.erase(key);  // Remove the group from the map
                }
            }
        }
        return result;  // Return the minimum number of rabbits
    }
};

/*
Explanation:
- The unordered map tracks the counts of groups of rabbits that have been formed.
- For each rabbit's answer, we determine if a new group needs to be added or an existing group needs to be updated.
- When a group is complete (i.e., the number of rabbits matches the group size), it is removed from the map.
- The result keeps track of the minimum number of rabbits required based on the groups formed.
*/
