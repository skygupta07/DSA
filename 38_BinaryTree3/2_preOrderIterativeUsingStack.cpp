#include<iostream>
#include <stack>
using namespace std;

class node{  // okay so leetcode uses ListNode or TreeNode and all to distinguish kaha ka node
public:
    int data;
    node* left;
    node* right;

    node(int data){ // constructor is initialised in the node class itself...
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void preOrderIterative(node* &root){  // since stack is filo so preOrder iterative will be 
                                           // root right left    i.e. {left, right} ki call reverse kar di..
    
    stack <node*> stk;
    if (root!=NULL) stk.push(root);  // to avoid null pointer exception
    // dudh ka jala chach bhi phook phook kar peeta hai ... even tum root bhi check karke
    // push kar rahe ho ki kahi mujhe root hi to null nahi de rakha na bc no....
    
    while(stk.size()>0){
        
        node* temp = stk.top();
        stk.pop();
        cout<<temp->data <<" ";

        if (temp->right !=NULL) stk.push(temp->right);   // since stkack
        if (temp->left !=NULL) stk.push(temp->left);

    }

}


int main(){
    node* a = new node(1);  // firstk node is the root node..
    node* b = new node(2);  // since humne upar node ki definition hi aisi likhi hai ki
                            // now har new node ke pass left aur right child node honge..
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    
    // connecting nodes
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    preOrderIterative(a);
}    

/*
preorder iterative yeh bhi same aapka bfs queue wale ke hi jaisa hai.....
bas queue mai aapka while (!q.empty())
to yaha while (st.size() > 0)

aur stack to aapka order reverse kar deta hai to humne bhi kar diya ...
preorder iterative mai appka root right left kar diya..
*/