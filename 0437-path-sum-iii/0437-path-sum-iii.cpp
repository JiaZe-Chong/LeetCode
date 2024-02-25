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
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum, true);
    }
    
    int dfs(TreeNode* root, long long sum, int targetSum, bool isMain) {
        if (!root) return 0;
        
        long long ans = 0;
        int val = root->val;
        if (sum + val == targetSum) ans++;
        
        ans += dfs(root->left, sum + val, targetSum, isMain);
        ans += dfs(root->right, sum + val, targetSum, isMain);
        
        if (isMain) {
            ans += dfs(root->left, 0, targetSum, false);
            ans += dfs(root->right, 0, targetSum, false);
        }
        
        return ans;
    }
};