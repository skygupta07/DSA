// createBinaryTreeFromDescription.cpp

/*

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] 
indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.

Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.


Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]

Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]

Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.


Constraints:

1 <= descriptions.length <= 1e4

descriptions[i].length == 3
1 <= parenti, childi <= 1e5

0 <= isLefti <= 1
The binary tree described by descriptions is valid.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {

      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


class Solution {
public:

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // nodeMap: yeh har node value ka corresponding TreeNode pointer store karega
        unordered_map <int, TreeNode*> nodeMap;

        // hasParent: batata hai ki koi node kisi ka child hai ya nahi
        // jiska parent hoga usko 'true' mark karenge

        // ye hasParent wala isliye hi bana rahe h taaki baad mai jaake root node ko find kar sake...
        unordered_map <int, bool> hasParent;

        // step-1: Tree construct karna based on descriptions
        for (const auto &desc: descriptions){

            int parentVal = desc[0];  // parent node ki value
            int childVal = desc[1];   // child node ki value
            bool isLeft = desc[2];    // 1 matlab left child, 0 matlab right child


            // agar parent node pehli baar aa rahi hai to uska ek naya TreeNode banao
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }

            // parent node ka pointer le lo
            TreeNode* parent = nodeMap[parentVal];

            // agar child node pehli baar aa rahi hai to uska bhi TreeNode banao
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // child node ka pointer le lo
            TreeNode* child = nodeMap[childVal];

            // agar isLeft true hai to child ko left me lagao, warna right me
            if (isLeft) parent->left = child;
             
            else parent->right = child;

            // child node kisi ka child hai, toh uska parent zarur hoga
            hasParent[childVal] = true;
        }

        // step-2: root node dhoondo
        // root node wahi hoti hai jiska koi parent nahi hota
        TreeNode* root = NULL;

        for (auto pair : nodeMap) {
            int nodeVal = pair.first;
            TreeNode* node = pair.second;

            // agar is node ka koi parent nahi hai, toh wahi root hoga
            if (!hasParent[nodeVal]) {
                root = node;
                break;
            }
        }

        return root;
        
    }
};

