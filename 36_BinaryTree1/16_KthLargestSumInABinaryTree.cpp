// kthLargestSumInABinaryTree.cpp


#include <bits/stdc++.h>
using namespace std;


/*

You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). 
If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

Example 1:

Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13

Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.


Example 2:

Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 1e5
1 <= Node.val <= 1e6
1 <= k <= n

*/



//  Definition for a binary tree node.

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

    int findLevel(TreeNode* root){
        if (root == NULL) return 0;

        return 1 + max(findLevel(root->left) , findLevel(root->right));
    }

    void bfs(TreeNode* &root, priority_queue <long long> &pq){
        if (root == NULL) return;

        queue <TreeNode*> q;
        q.push(root);
    
        while (!q.empty()){
            int qSize = q.size();

            long long lSum = 0; // stores level sum
 
            for (int i=0; i<qSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                lSum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            pq.push(lSum);
        }
    }


    long long kthLargestLevelSum(TreeNode* root, int k) {

        int levels = findLevel(root);

        if (levels < k) return -1;

        priority_queue <long long> pq;

        bfs(root, pq);

        // kth largest nikalna hai to maxheap bana ke then akash (k-- > 1)
        // {mujhe ye yaad h ki mai kucch jyada hi soch raha tha ki minheap banau ya kya ...}

        while(k-- > 1 && !pq.empty()){ 
            pq.pop();
        }

        return pq.top();
    }
};