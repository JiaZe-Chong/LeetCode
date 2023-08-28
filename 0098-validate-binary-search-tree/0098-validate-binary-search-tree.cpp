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
    bool isValidBST(TreeNode* root) {
        
        if ( !root ) return true;
        
        int ans = true;
        
        if ( !isSmaller( root->left, root->val ) || !isBigger( root->right, root->val ) ) return false;
        
        return isValidBST( root->left ) && isValidBST( root->right );
    }
    
    bool isSmaller( TreeNode* root, int num ) {
        
        if ( !root ) return true;
        
        return ( root->val < num && isSmaller( root->left, num ) && isSmaller( root->right, num ) );
    }
    
    bool isBigger( TreeNode* root, int num ) {
        
        if ( !root ) return true;
        
        return ( root->val > num && isBigger( root->left, num ) && isBigger( root->right, num ) );
    }
};