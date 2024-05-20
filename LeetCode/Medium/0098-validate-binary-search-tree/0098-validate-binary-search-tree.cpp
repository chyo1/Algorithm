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

    bool isPossible(long long leftVal, TreeNode* node, long long rightVal) {
        if (node == NULL)
            return true;
        if (leftVal < node->val && node->val < rightVal) 
            return isPossible(leftVal, node->left, node->val) && isPossible(node->val, node->right, rightVal);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        long long minVal = -1'000'000'000'000, maxVal = 1'000'000'000'000;
        return isPossible(minVal, root, maxVal);
    }
};