/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        unordered_set<int> childs;
        unordered_map<int, TreeNode*> nodes;

        for (int i = 0; i < descriptions.size(); i++) {
            int parentVal = descriptions[i][0], childVal = descriptions[i][1], isLeft = descriptions[i][2];

            TreeNode* newChild = findNode(nodes, childVal);
            TreeNode* newParent = findNode(nodes, parentVal);

            childs.insert(childVal);

            if (!newChild) {
                newChild = new TreeNode(childVal);
                nodes.insert({childVal, newChild});
            }
            if (!newParent) {
                newParent = new TreeNode(parentVal);
                nodes.insert({parentVal, newParent});
            }
            if (isLeft)
                newParent->left = newChild;
            else
                newParent->right = newChild;
        }

        for (auto iter = nodes.begin(); iter != nodes.end(); iter++) {
            int val = iter->first;
            if (childs.find(val) == childs.end())
                return iter->second;
        }
        return root;
    }

    TreeNode* findNode(const unordered_map<int, TreeNode*>& nodes, int val) {        
        auto iter = nodes.find(val);

        return iter == nodes.end() ? NULL : iter->second;
    }
};