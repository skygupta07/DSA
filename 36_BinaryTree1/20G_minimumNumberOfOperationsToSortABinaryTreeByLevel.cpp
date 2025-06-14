#include <bits/stdc++.h>
using namespace std;

/*

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted 
in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 
Example 1:

Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3

Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.


Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3

Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.


Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0

Explanation: Each level is already sorted in increasing order so return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 1e5].
1 <= Node.val <= 1e5
All the values of the tree are unique.

*/




//  Definition for a binary tree node.

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

    // Helper function to calculate minimum number of swaps required to sort the array
    int countSwap(vector<int>& arr){
        int n = arr.size();

        // Pehle har element ke sath uska index store karo
        vector <pair <int, int>> indexedArr;

        for (int i = 0; i < n; ++i) {
            // el, idx
            indexedArr.push_back({arr[i], i});
        }

        // Sort karo based on value, taaki hume pata chale kisko kahan hona chahiye
        sort(indexedArr.begin(), indexedArr.end());

        vector <bool> visited(n, false);  // Ye track karega ki koi element already cycle me visit hua ya nahi
        
        int swaps = 0;

        for (int i = 0; i < n; i++) {

            // Agar already sahi position pe hai ya visit ho chuka hai, skip
            if (visited[i] || indexedArr[i].second == i) continue;

            // Cycle detection
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;  // Jump to next index where element should be
                cycleSize++;
            }

            // Ek cycle of size k ko sort karne ke liye (k - 1) swaps lagte hain
            if (cycleSize > 1)
                swaps += (cycleSize - 1);
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        int totalOps = 0;

        // Standard level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            // Ek level ke sare nodes process karo
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Is level ke sorted form mai convert hone ke liye kitne swaps lagenge, wo count karo
            totalOps += countSwap(levelValues);
        }

        return totalOps;
    }
};
