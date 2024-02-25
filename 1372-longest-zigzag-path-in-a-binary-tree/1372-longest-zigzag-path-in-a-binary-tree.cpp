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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans);
        dfs(root, false, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, bool goLeft, int steps, int& ans) {
        if (!root)
            return;
        
        ans = max(ans, steps);
        
        if (goLeft) {
            dfs(root->right, false, steps + 1, ans);
            dfs(root->left, true, 1, ans);
        }
        else {
            dfs(root->right, false, 1, ans);
            dfs(root->left, true, steps + 1, ans);
        }
    }
};