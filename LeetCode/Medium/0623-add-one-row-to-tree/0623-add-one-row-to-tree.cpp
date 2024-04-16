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

        // depth 1일 때 예외처리
        if (depth == 1) {
            TreeNode *newRoot;

            newRoot = new TreeNode(val, root, NULL);

            return newRoot;
        }
        
        while (!q.empty()) {
            TreeNode*now = q.front().first;
            int nowDepth = q.front().second;

            q.pop();

            // 다음 depth에 추가해야 되는 경우
            if (nowDepth + 1 == depth) {
                TreeNode* leftChild, *rightChild;

                // 자식 노드 추가 할당 및 val 값 입력
                leftChild = new TreeNode(val, now->left, NULL);
                rightChild = new TreeNode(val, NULL, now->right);
 

                // 삽입한 노드와 기존 노드 연결
                now->left = leftChild, now->right = rightChild;
            }    
            
            // 삽입해야 하는 위치 < 주어진 depth 일 경우 큐에 추가
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