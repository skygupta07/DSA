#include <bits/stdc++.h>
using namespace std;


/*

One way to serialize a binary tree is to use preorder traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as '#'.


For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", 
where '#' represents a null node.

Given a string of comma-separated values preorder, 
return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer
or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.


Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true


Example 2:

Input: preorder = "1,#"
Output: false


Example 3:

Input: preorder = "9,#,#,1"
Output: false
 

Constraints:

1 <= preorder.length <= 104
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.

*/

class Solution {
    public:
        bool isValidSerialization(string preorder) {
            int slots = 1;  // Root needs 1 slot
            
            for (int i = 0; i < preorder.size(); i++) {
                if (preorder[i] == ',') continue;  // Ignore commas
                
                // If no slots available before processing a node, return false
                if (slots == 0) return false;
    
                // If it's a number (either single or multi-digit)
                if (isdigit(preorder[i])) {
                    // Move index to skip multi-digit number
                    while (i < preorder.size() && isdigit(preorder[i])) i++;
                    i--; // Adjust index because for-loop increments it
                    slots += 1;  // Number creates two children but occupies one slot
                } 
                
                else { // It is a '#'
                    slots -= 1;  // Null consumes a slot
                }
            }
    
            return slots == 0; // All slots should be used exactly
        }
    };
    