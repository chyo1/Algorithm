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
private:
    vector <int> nodes;
public:
    bool isValidBST(TreeNode* root) {
        inOrder(root);
    
        int size = nodes.size();
        for (int i = 0; i < size - 1; i++) {
            if (nodes[i] >= nodes[i + 1])
                return false;
        }
        return true;
    }

    void inOrder(TreeNode* node) {
        if (node->left)
            inOrder(node->left);
        nodes.push_back(node->val);
        if (node->right)
            inOrder(node->right);
        return;
    }
};