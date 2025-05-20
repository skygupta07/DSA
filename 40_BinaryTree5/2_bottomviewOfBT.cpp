#include <bits/stdc++.h>
using namespace std;


class Node{ 
public:
    // data members
    int data;
    Node *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    Node(){
        this->data = 0;
        left = NULL;
    }
    Node(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// jab ghee seedhi ungli se na nikle to ungli tedhi karni padti hai...
// matalb jab vertical order traversal se samajh na aaye to horizontal order socha karo..

class Solution {
public:
    vector <int> bottomView(Node *root) {
        vector <int> ans;
        
        map <int, int> mp; // map to store the last node at each horizontal distance
        // horizontalDistance , NodeValue
        
        queue <pair <int, Node*> > q; // queue tree ko traverse karne ke liye use kar rahe h
        // horizontalDistance, sachmuchNode
        
        q.push({0,root});   // threshold
         
        // bfs
        while(!q.empty()){
            
            int hd = q.front().first;
            Node* curr = q.front().second; // current Node
            q.pop(); 
            
            // iss horizontal distance pe node ki value update karte jaooooooo...
            mp[hd] = curr->data;
            
            // agar left exist karta hai to hd-1 karke left daal diya queue mai...
            if(curr->left) q.push({hd-1, curr->left});
            if(curr->right) q.push({hd+1, curr->right});
              
        }
        
        for(auto [hd, nodeVal] : mp) ans.push_back(nodeVal);
        
        return ans;
    }
};