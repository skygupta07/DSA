#include <bits/stdc++.h>
using namespace std;

/*

There is a forest with an unknown number of rabbits. 
We asked n rabbits "How many rabbits have the same color as you?" 
and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Example 2:

Input: answers = [10,10,10]
Output: 11
 

Constraints:

1 <= answers.length <= 1000
0 <= answers[i] < 1000

*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // Create an unordered map to track the count of groups of rabbits with the same color
        unordered_map <int, int> mp;

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


// ---------------

class Solution { //  wrong code 
public: 
    int numRabbits(vector<int>& answers) {
        int zeroCount = 0;
        unordered_set <int> st;

        for (int i=0; i<answers.size(); i++){
            if (answers[i] == 0) zeroCount++;
            else{
                st.insert(answers[i]);
            }
        }

        int finalCount = zeroCount;

        for (auto el : st) finalCount += el + 1;

        return finalCount;
    }
};

/*
mere alawa zero bande h mere jaise matlab mai khud mai hi unique hu...
otherwise koi bolta h ki mere jaise 3 log aur h to matlab unka contribution 4 ka hoga..

ekdum same answer dene wale same group ke hi part ho sakte h ...so set use kiya...

magar ye yaha fail ho gya 

Wrong Answer
34 / 56 testcases passed


Editorial
Input
answers =
[0,0,1,1,1]

Use Testcase
Output
4
Expected
6
*/



class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int, int> freq; // har answer ki frequency count karenge

        for (int ans : answers) {
            freq[ans]++;
        }

        int total = 0; // total number of rabbits

        // for (auto el : mp) se accha option rehta h ..
        // for (auto &[key, value] : mp) 
        for (const auto &[x, count] : freq) {
            
            if (x == 0) {
                total += count; // agar answer 0 hai toh har rabbit unique hai
            } 

            else {
                int groupSize = x + 1; // ek group mein max x+1 rabbits ho sakte hain

                // bas yaha groups nikalna hi main task h ..
                int groups = (count + groupSize - 1) / groupSize; // ceil(count / groupSize)
                
                total += (groups * groupSize); // har group ka contribution add kar diya
            }
        }

        return total;
    }
};


/*

Use a map to count frequency of each answer.

For each unique answer x:
Group size = x + 1

Number of such rabbits = count
Total groups needed = ceil(count / (x + 1))

So, total rabbits contributed = groups * (x + 1)

*/




