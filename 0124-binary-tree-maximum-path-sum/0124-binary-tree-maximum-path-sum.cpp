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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        dfs( root, mx );
        return mx;
    }
    
    int dfs( TreeNode* node, int& maxPath ) {
        
        if ( !node ) return 0;
        
        int left = max( dfs( node->left, maxPath ), 0 );
        int right = max( dfs( node->right, maxPath ), 0 );
        
        int curPath = node->val + left + right;
        
        maxPath = max( curPath, maxPath );
        
        return node->val + max( left, right );
        
    }
};