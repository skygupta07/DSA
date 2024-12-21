/*


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            vector <int> level;     // har level ke ye vector dubara se initialise ho jaega
            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // if that node left right exist then only push it into queue
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


/*
1. create vector of vector to store each level
2. nalla base case if (root == NULL) return -> i.e. empty tree given
3. create queue (chahe creation ho ya traversal .. yaha queue hi malik hai...)
4. push root into queue
5.* isme yahi catch hai ki jab queue empty ho jaega tab pura traversal ho gya hoga otherwise repeatedly ussey hi karo
6. create vector to store each level
7. ab jaan buj ke andar waale loop ko bas queue.size tak hi chalayenge...because utne hi element honge
// uss level mai.....

8. issey bas kewal kaam ke nodes hi aaye 
9. ans mai level push_back kara

// t.c. = O(N) and S.C. = O(N) due to queue

each element of the queue is storing TreeNode* i.e. it will have access to TreeNode->val , left and right

*/

