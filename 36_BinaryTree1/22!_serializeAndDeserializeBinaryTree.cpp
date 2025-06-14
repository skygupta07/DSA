// serializeAndDeserializeBinaryTree.cpp

/*
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection 
link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string 
can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. 

You do not necessarily need to follow this format, so please be creative and come up with different 
approaches yourself.



Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]


Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000


*/

#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 
class Codec {
public:

    // Yeh function queue se ek ek node nikal kar Binary Tree reconstruct karega
    TreeNode* deserialize_helper(queue<string> &q) {
        string s = q.front(); // Queue ke front se ek string le rahe hain
        q.pop(); // Usko queue se hata diya

        if(s == "NULL") return NULL; // Agar NULL mila toh wapas NULL return kar diya

        // Jo value mili usse ek naye node banai
        TreeNode* root = new TreeNode(stoi(s));
        
        // Pehle left subtree ko build karenge
        root->left = deserialize_helper(q);

        // Phir right subtree ko build karenge
        root->right = deserialize_helper(q);
        
        return root; // Final tree ka root return karenge
    }

    // Tree ko string format me convert karenge
    string serialize(TreeNode* root) {
        if(!root) return "NULL,"; // Agar root NULL hai toh "NULL," return karenge
        // Root ki value + Left Subtree + Right Subtree ko serialize karenge
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Encoded string ko wapas Binary Tree me convert karenge
    TreeNode* deserialize(string data) {
        queue<string> q; // Queue use karenge taki ek ek node process ho sake
        string s;

        // String ko ',' ke basis pe split karenge
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == ',') {
                q.push(s); // Queue me ek ek part daalenge
                s = ""; // String ko reset kar diya
                continue;
            }
            s += data[i]; // Current character ko string me add kar rahe hain
        }

        if(s.size() != 0) q.push(s); // Last element ko bhi queue me daal diya

        return deserialize_helper(q); // Queue ko pass karke tree reconstruct karenge
    }

};

// Example Usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
