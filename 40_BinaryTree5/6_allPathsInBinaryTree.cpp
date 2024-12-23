void dfs(Node* root , vector<vector<int>> &result, vector <int> path){
    if (root == NULL ) return;  // nalla
    path.push_back(root -> data);   // threshold -=> very first step or root node
    
    if (root -> left == NULL && root -> right == NULL){ // leaf node 
        result.push_back(path);
    }
    
    else{   // recursive dfs calls
        if (root -> left ) dfs(root->left, result, path);
        if (root -> right) dfs(root -> right, result, path);
    }
    
    // backtrack
    path.pop_back();
    
    
}

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;    // nalla
        
        vector <int> path;

        dfs(root, result, path);
        
        return result;
        // dfs
    }
};