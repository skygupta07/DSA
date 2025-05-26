// textJustification

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of strings words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line does not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]


Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.


Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth


*/

class Solution {
public:

    vector <string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> ans;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            // Step 1: Determine how many words can fit in the current line.
            int lineStart = i;
            int lineLength = words[i].size();
            i++;

            while (i < n && lineLength + 1 + words[i].size() <= maxWidth) {
                lineLength += 1 + words[i].size(); // Add space and next word length.
                i++;
            }
            
            // Step 2: Build the current line.
            string line;
            int numWords = i - lineStart; // Number of words in this line.
            int totalSpaces = maxWidth - lineLength + (numWords - 1); // Total spaces to distribute. (numWords - 1  = minNum of spaces)
            
            if (numWords == 1 || i == n) {
                // Left-justify if it's the last line or only one word fits.
                for (int j = lineStart; j < i; j++) {
                    line += words[j];
                    // ekdum last mai space lagane ki no need
                    if (j != i - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' '); // Fill remaining spaces.
            }
            else {
                // Fully-justify the line.
                int spacesBetweenWords = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1); // Leftover spaces.
                
                for (int j = lineStart; j < i; j++) {
                    line += words[j];
                    if (j != i - 1) {
                        line += string(spacesBetweenWords + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }
            
            ans.push_back(line);
        }
        return ans;
    }
};
