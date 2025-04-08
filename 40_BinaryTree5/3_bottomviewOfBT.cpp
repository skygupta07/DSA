#include <bits/stdc++.h>
using namespace std;


// jab ghee seedhi ungli se na nikle to ungli tedhi karni padti hai...
// matalb jab vertical order traversal se samajh na aaye to horizontal order socha karo..

class Solution {
public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        
        map <int,int> mp; // map to store the last node at each horizontal distance
        // horizontalDistance , NodeValue
        
        queue <pair <int, Node*> > q; // queue tree ko traverse karne ke liye use kar rahe h
        // horizontalDistance, sachmuchNode
        
        q.push({0,root});   // threshold
         
        // bfs
        while(!q.empty()){
            
            int hd = q.front().first;
            Node* temp = q.front().second;
            q.pop();
            
            // iss horizontal distance pe node ki value update karte jaooo...
            mp[hd] = temp->data;
            
            // agar left exist karta hai to hd-1 karke left daal diya queue mai...
            if(temp->left){
                q.push({hd-1,temp->left});
            }
            
            if(temp->right){
                q.push({hd+1,temp->right});
            }    
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};