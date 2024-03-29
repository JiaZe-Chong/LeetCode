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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs( root, root->val, ans );
        return ans;
    }
    
    void dfs( TreeNode* root, int mx, int& num ) {
        
        if ( !root ) return;
        
        if ( root->val >= mx ) num++;
        
        mx = max(mx, root->val);
        dfs( root->left, mx, num );
        dfs( root->right, mx, num );
    }
};