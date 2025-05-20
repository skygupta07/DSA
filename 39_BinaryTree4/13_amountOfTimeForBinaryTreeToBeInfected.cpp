#include <bits/stdc++.h>
using namespace std;

/*

You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.


Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.

*/


//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
    public:
        // Function to build the adjacency list from the binary tree without recursion
        void buildAdjList(TreeNode* root, unordered_map <int, vector<int>> &adjList) {
            if (!root) return; // nalla
            
            queue <TreeNode*> q;
            q.push(root);
            
            // tree ko solve karne chale aur tree ko traverse nahi kiya to phir kya hi kiya...
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) {
                    adjList[node->val].push_back(node->left->val);
                    adjList[node->left->val].push_back(node->val);

                    q.push(node->left);
                }
                
                if (node->right) {
                    adjList[node->val].push_back(node->right->val);
                    adjList[node->right->val].push_back(node->val);

                    // isko jisne bhi ignore kiya uska game to bajna confirm h...
                    q.push(node->right);
                }
            }
        }
    
        // Function to calculate the number of minutes to infect the entire tree
        int amountOfTime(TreeNode* root, int start) {
            if (!root) return 0;
            
            unordered_map <int, vector<int>> adjList;
            buildAdjList(root, adjList);
            
            queue <int> q;
            q.push(start);

            unordered_set <int> visited;
            visited.insert(start);  // i forget sometime
            
            int minutes = -1;
            
            while (!q.empty()) {
    
                int qSize = q.size();
    
                for (int i = 0; i < qSize; i++){
                    int node = q.front(); // node or curr or temp
                    q.pop();
    
                    for (int neighbor : adjList[node]) {
                        
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                // har level ke baad 
                minutes++;
            }
            
            return minutes;
        }
    };
    
    
    
    /*
    kisi bhi node ke paas max teen hi cheej ho sakti hai...
    1 parent , aur 2 child
    
    agar mereko simply root node infected diya hota... tab to simply number of levels se pata lag jata...
    but yaha infected node kahi bhi ho sakta hai...
    
    binary tree mai kisi bhi node ke paas at a time bas uske child ka hi access hota hai...
    wo apne parent ko nahi pehchan sakta..... matlab yaha kucch jugaad karna padega...
    parent ki mapping kar dete hai...

    accha parent apne child ko phechan leta h ...but wahi child apne parent ko nahi pehchan paata easily..
    
    so basically the amount of time is the (number of levels - 1) in the tree 
    from the perspective of the infected starting node...(example : bent karke tree dekh liya...)
    
    
    algo : 
    first find the infected node in the tree
    hashmap banana padega taaki child ke saath saath parent ko bhi access kar saku....
    (child, parent) ka connection bana diya...

    ek queue <pair <node, int>>  maintain karunga.... 
        queue mai push karunga... 
            har baar teen cheeje left ,right, parent check karunga ...

                and agar wo exist kartey hai and abhi tak visited nahi hai to ek level badha ke 
                dubara se queue mai push kar dunga...aur isInfected mai bhi daal diya karo...
    


    step 1 -> find the node with given value start
    step 2 -> mark the parent
    
    
    */