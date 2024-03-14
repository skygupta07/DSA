/*

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> result;
        if (root == NULL) return result;
        bool flag = 1;  // means left to right traversal
        queue <TreeNode*> nodeq;
        nodeq.push(root);

        while (!nodeq.empty()){
            int size = nodeq.size();
            vector <int> row(size);
            // front po push
            

            for (int i=0; i<size; i++){
                TreeNode* node = nodeq.front();
                nodeq.pop();

                // find position to fill the node's value
                int idx = (flag) ? i : (size-1-i);
                row[idx] = node->val;

                if (node->left) nodeq.push(node->left);
                if (node->right) nodeq.push(node->right);
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;  
    }
};



// using queue we do normal level Order Traversal 
/* now we will maintain a bool flag which will help us to fill the result in zig zag pattern 
complement the flag after each level....


*/