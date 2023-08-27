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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {        
        
        bool b1 = isSubtreeHelp( root, subRoot );
        bool b2 = root->left ? isSubtree( root->left, subRoot ) : false;
        bool b3 = root->right ? isSubtree( root->right, subRoot ) : false;
        
        return b1 || b2 || b3;
        
    }
    
    bool isSubtreeHelp(TreeNode* root, TreeNode* subRoot) {
        if ( !root && !subRoot ) return true;
        if ( !root ) return false;
        if ( !subRoot ) return false;
        
        return root->val == subRoot->val && isSubtreeHelp( root->left, subRoot->left ) && isSubtreeHelp( root->right, subRoot->right );
    }
};