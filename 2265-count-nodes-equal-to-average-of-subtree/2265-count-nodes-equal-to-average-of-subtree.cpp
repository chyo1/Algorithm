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
    int cnt = 0;
    int averageOfSubtree(TreeNode* root) {
        findSub(root);
        return cnt;
    }

    pair<int, int> findSub(TreeNode* node) {
        pair<int, int> valSum = {node->val, 1};
        if (node->left) {
            pair<int, int> ret = findSub(node->left);
            valSum.first += ret.first;
            valSum.second += ret.second;
        }
        if (node->right) {
            pair<int, int> ret = findSub(node->right);
            valSum.first += ret.first;
            valSum.second += ret.second;
        }

        int avg = valSum.first / valSum.second;
        if (avg == node->val)
            cnt++;
        return valSum;
    }
};