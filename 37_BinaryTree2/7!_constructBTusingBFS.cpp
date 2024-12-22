#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// bfs matlab to po print push
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(q.size()>0){
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if (temp->left !=NULL) q.push(temp->left);
        if (temp->right !=NULL) q.push(temp->right);
    }
    cout<<endl;
}

node* construct(int arr[], int n){
    queue <node*> q;
    node* root = new node(arr[0]);
    q.push(root);
    int i = 1;  // zeroth index le liye 1 2 index se dekhna start karo...
    int j = 2;
    while(q.size()>0 && i<n){  // i<n because aisa ho sakta hai ki queue mai element rah gaye 
                                // but tree to puri construct ho chuki thi...
        node* temp = q.front();
        q.pop();
        node* l;    // do naye node banaye waha lagane ke liye...
        node* r;

        if(arr[i]!=INT_MIN) l=new node(arr[i]);
        else l=NULL;    // agar INT_MIN wala nikla array se to tree mai to bhai NULL hi hoga na attach

        // i last index pe ho but j aage nikal chuka hu...
        if(j!=n && arr[j]!=INT_MIN) r=new node(arr[j]); 
        else r=NULL;

        // establish connection with temp
        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);  // wahi q ke front waale elements mai attach kiya..
        if(r!=NULL) q.push(r);

        // increment i and j
        i+=2;
        j+=2;
        
    }
    return root;
}


int main(){
    int arr[]={1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = construct(arr,n);  // puri tree bana ke tree ka tangna de dega (root)
    levelOrder(root);   // print karne ke liye
}

// null ko INT_MIN se represent kara....
// -1 bhi rakh sakte ho but then all other elements should be positive'



/*
pehle tree ko construct hum manually kar rahe they ek ek node banao then 
link establish karo but that is a kid method 

-> tabhi leetcode pe saare trees ke input as a array di hoti thi...
-> so construct a binary tree from a given array...

-> agar array di bhi hoti hai to usko hum level order wise traverse karke padhte 
-> hai... 


*/
