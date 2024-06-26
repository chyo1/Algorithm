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
    vector<int> ans;
    int rightSideVisited[101] = {false, };

    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return ans;

        getRightSideView(root, 0, true);
        return ans;
    }

    void getRightSideView(TreeNode* now, int lev, bool isRight) {

        if (!rightSideVisited[lev]) {
            ans.push_back(now->val);
            rightSideVisited[lev] = true;
        }

        if (now->right)
            getRightSideView(now->right, lev + 1, true);
        if (now->left)
            getRightSideView(now->left, lev + 1, false);

    }
};
