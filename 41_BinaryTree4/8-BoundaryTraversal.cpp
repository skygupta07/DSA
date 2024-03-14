/*

bool isLeaf(TreeNode<int>* root){
    return ( !(root->left) && !(root->right) );
}

void addLeftBoundary(TreeNode<int>* root, vector <int> &result){
    TreeNode<int>* curr = root->left;
    while (curr){
        if (!isLeaf(curr)) result.push_back(curr->data);
        // for next iterations
        if (curr->left)  curr = curr->left;
        else curr = curr->right;
    }

}

void addLeafNodes(TreeNode<int>* root, vector <int> &result){    // inorder travesal
    if (isLeaf(root)){
        result.push_back(root->data);
    }

    if (root->left) addLeafNodes(root->left, result);
    if (root->right) addLeafNodes(root->right , result);
}




void addlRightBoundary(TreeNode<int>* root, vector <int> &result){
    TreeNode<int>* curr = root->right;
    vector <int> temp;  // to store the right traversal in reverse order

    while (curr){
        if (!isLeaf(curr)) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i=temp.size()-1 ; i>=0; --i){
        result.push_back(temp[i]);
    }
}



vector<int> traverseBoundary(TreeNode<int> *root){
    vector<int> result;
    if (!root) return result;
    if (!isLeaf(root)) result.push_back(root->data);
    addLeftBoundary(root,result);
    addLeafNodes(root,result);
    addlRightBoundary(root,result);
    return result;
}


/*
----traversing tree anticlockwise
1. push root into result
2. left traversal excluding leaf nodes -> go go left if left not present then 
you may go right...
3. add leaf nodes using inorder traversal  -> taki sach mai hi ekdum neeche wale 
hi elements mile....

4. right traversal (in reverse direction )excluding leaf nodes -> go go right if right not present then
go left

because traverse to hum root se hi karte hai i.e root->left or root-> right ki call 
laga di...

handy method -> if (!root)     ===   if (root == NULL) 

agar mene teeno helper fn mai root ko reference se pass kar diya hota tab to
wo uski le leta tareeke se ...har helper fn root ko pel ke chhod deta .. so better 
is ki you pass simply or copy of the root only


ye coding ninja walo ke alag chochle hai template dekhni hi padti hai tumhe 
TreeNode <int> *root    pass karwana hai yaha....
*/