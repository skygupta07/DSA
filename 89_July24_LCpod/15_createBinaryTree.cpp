class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, bool> hasParent;

        for (auto desc: descriptions){
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];

            // agara parent val pehle se map mai nahi hai.....to map mai daalo..
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            // aur parentnode create bhi karo...
            TreeNode* parent = nodeMap[parentVal];

            if (nodeMap.find(childVal) == nodeMap.end()){
                nodeMap[childVal] = new TreeNode(childVal);
            }

            TreeNode* child = nodeMap[childVal];

            if (isLeft) parent->left = child;
            else parent->right = child;

            // obviously child lagaya hai to child ke parent ko true karo..

            hasParent[childVal] = true;
        }

        // now tree has been created now nodeMap ka use karke and hasParent ka use karke dekho ki kis node ka parent ka nahi hai ... jiska bhi parent nahi hoga wo root node hoga..


        TreeNode* root = NULL;
        for (auto pair : nodeMap){
            if (!hasParent[pair.first]){
                root = pair.second;
                break;
            }
        }

        return root;
    }
};


