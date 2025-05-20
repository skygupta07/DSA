#include <bits/stdc++.h>
using namespace std;

/*
top view of binary tree...

root se left left left jaate raho until reaches null node..then wapas aate waqt include 
karna hai...

root se right right right jaate raho until reaches null node..then jaate hi waqt include 
karna hai is baar ...

return final vector..
*/



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


class Solution {
public:
    vector <int> topView(Node* root) {
        vector<int> ans;
        // ye chiz mene dekhi h ki jab bhi vector wali chiz return karni hoti h to... phir vector 
        // banake then !root wali condition check karke turant vector return kar dete hai...

        if (!root) return ans;  // nalla

        // Map to store the first node at each horizontal distance
        // map mai horizontal distance ko pehle rakhna jaruri h .... baaki to sab chalta h..
        map <int, int> topNodeMap; // horizontal distance, node data

        // Queue to perform BFS
        queue <pair <Node*, int>> q; // node, horizontal distance

        // Start BFS from the root with horizontal distance 0
        q.push({root, 0});

        while (!q.empty()) {
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // If this horizontal distance is being visited for the first time
            // agar koi horizontal distance pehle se map mai hai to kyu hi kucch karna h..
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = node->data;
            }

            // ab uske children ko push karna hoga...
            // Move to the left child
            if (node->left) q.push({node->left, hd - 1});

            // Move to the right child
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract the top view nodes from the map
        // map isliye hi use kiya hai taaki ....sorted form mai like -2 -1 0 1 2 
        // karke horizontal distance mile hume....
        
        for (auto it : topNodeMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
exactly bottom view ki tarah hi hai .. bas ab yaha constraint aur laga diya ...
ki jo ith horizontal distance par very first element ko hi include karna hai..

*/