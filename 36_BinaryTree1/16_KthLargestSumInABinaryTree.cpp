#include <bits/stdc++.h>
using namespace std;

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

            long long lSum = 0;

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

        while(k-- > 1 && !pq.empty()){ // kth largest nikalna hai matlab akash k-- > 1
        
            pq.pop();
        }

        return pq.top();
    }
};