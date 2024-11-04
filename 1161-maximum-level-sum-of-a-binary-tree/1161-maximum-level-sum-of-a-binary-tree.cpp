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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int mx = root->val;
        int level = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        while(q.size()) {
            int num = q.size();
            int cur = 0;
            level++;
            while (num--) {
                TreeNode* node = q.front();
                cur += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            if (cur > mx) {
                mx = cur;
                ans = level;
            }
        }
        return ans;
    }
};