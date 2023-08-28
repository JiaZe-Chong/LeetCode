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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder( root, k, ans );
        return ans;
    }
    
    void inorder( TreeNode* node, int& k, int& ans ) {
        
        if ( !node ) return;
        
        inorder( node->left, k, ans );
        k--;
        if ( k == 0 ) ans = node->val;
        inorder( node->right, k, ans );
        
    }
    
    
};