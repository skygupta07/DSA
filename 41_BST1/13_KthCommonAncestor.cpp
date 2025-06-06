#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *left, *right;
};

class Solution{
public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y){

        vector <int> arr;
        Node* temp = root;

        int mn = min(x,y);
        int mx = max(x,y);
        
        while(temp!=NULL){
            if (temp->data < mn){
                arr.push_back(temp->data);
                temp = temp ->right;
            } 
            else if (temp->data > mx){
                arr.push_back(temp->data);
                temp = temp->left;
            }
            else{
                arr.push_back(temp->data);
                if (k>arr.size()) return -1;
                return arr[arr.size() - k];
            }
        }
        return -1;
    }
};


// kth common ancestor

/*

when u get a node in range between  [min,max] 
this node will be lowest common ancestor LCS right... 
(i.e.  ancestor which is nearest to X and Y)

therefore when u are traversing from root node to lowest common ancestor, 
the nodes u have traversed are also ancestors with rank (p, p-1, p-2, ....2, 1) 
where p is number of possible ancestors   (if k > p simply return -1)

so when u are traversing from root to LCS keep track of node u have traverse and their sequence 
will tell u rank of ancestor

*/
