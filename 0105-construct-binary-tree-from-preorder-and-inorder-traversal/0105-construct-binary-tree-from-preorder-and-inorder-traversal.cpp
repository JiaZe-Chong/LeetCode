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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return build( preorder, inorder, ind, 0, inorder.size() - 1 );    
    }
    
    TreeNode* build( const vector<int>& preorder, const vector<int>& inorder, int& ind, int i, int j ) {
        
        if ( i > j ) return nullptr;
        
        TreeNode* root = new TreeNode( preorder[ind] );
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[ind] == inorder[i]) {
                split = i;
                break;
            }
        }
        ind++;
        
        root -> left = build( preorder, inorder, ind, i, split - 1 );
        root -> right = build( preorder, inorder, ind, split + 1, j );
        
        return root;
        
    }
};