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

typedef pair<TreeNode*, int> pp;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<pp> q;

        q.push({root, 1});
        
        if (depth == 1) {
            TreeNode *newRoot;
            
            newRoot = new TreeNode;
            newRoot->val = val;
            newRoot->left = root;
            newRoot->right = NULL;
            return newRoot;
        } 
        while (!q.empty()) {
            TreeNode*now = q.front().first;
            int nowDepth = q.front().second;

            q.pop();

            if (nowDepth + 1 == depth) {
                TreeNode* leftChild, *rightChild;

                leftChild = new TreeNode;
                rightChild = new TreeNode;
 
                
                leftChild->val = rightChild->val = val;
                
                leftChild->left = leftChild->right = rightChild->left = rightChild->right = NULL;
                
                if (now->left)
                    leftChild->left = now->left;

                if (now->right)
                    rightChild->right = now->right;

                now->left = leftChild, now->right = rightChild;
            }      
            else if (nowDepth < depth)
            {
                if (now->left)
                    q.push({now->left, nowDepth + 1});
                if (now->right)
                    q.push({now->right, nowDepth + 1});
            } 
        }
        return root;
    }
};