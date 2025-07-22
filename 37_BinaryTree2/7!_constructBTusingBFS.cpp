#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};


// bfs matlab to po print push
void levelOrder(TreeNode* root){

    queue <TreeNode*> q;
    q.push(root);

    // or while (!q.empty())
    while(q.size() > 0){ 

        TreeNode* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";

        if (temp->left !=NULL) q.push(temp->left);
        if (temp->right !=NULL) q.push(temp->right);
    }

    cout<<endl;
}

TreeNode* construct(int arr[], int n){
    queue <TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;  // zeroth index ke liye 1 2 index se dekhna start karo...
    int j = 2;


    // i<n because aisa ho sakta hai ki queue mai element rah gaye 
    // but tree to puri construct ho chuki thi...

    while(q.size() > 0 && i<n){  
        TreeNode* temp = q.front();
        q.pop();

        // do naye TreeNode banaye waha lagane ke liye...
        TreeNode* l;    
        TreeNode* r;

        if(arr[i] != INT_MIN) l = new TreeNode(arr[i]);
        else l = NULL;    // agar INT_MIN wala nikla array se to tree mai to bhai NULL hi hoga na attach

        // i last index pe ho but j aage nikal chuka hu... {aur condition aap aage wale index pe hi lagaya karo...}
        if(j != n && arr[j] != INT_MIN) r = new TreeNode(arr[j]); 
        else r = NULL;

        // establish connection with temp
        temp->left = l;
        temp->right = r;

        // wahi q ke front waale elements mai attach kiya..

        // now for further processing 
        if(l != NULL) q.push(l);  
        if(r != NULL) q.push(r);

        // increment i and j
        i += 2;
        j += 2;    
    }
    
    return root;
}


int main(){
    int arr[]={1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = construct(arr,n);  // puri tree bana ke tree ka tangna de dega (root)
    levelOrder(root);   // print karne ke liye
}


// null ko INT_MIN se represent kara....
// -1 bhi rakh sakte ho but then all other elements should be positive'


/*
pehle tree ko construct hum manually kar rahe they ek ek TreeNode banao then 
link establish karo but that is a kid method 

-> tabhi leetcode pe saare trees ke input as a array di hoti thi...
-> so construct a binary tree from a given array...

-> agar array di bhi hoti hai to usko hum level order wise traverse karke padhte 
-> hai... 


*/
