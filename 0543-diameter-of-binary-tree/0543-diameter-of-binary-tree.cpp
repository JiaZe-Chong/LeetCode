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
    int diameterOfBinaryTree(TreeNode* root) {
        return path(root).first;
    }
    
    pair<int, int> path(TreeNode* root) {
        
        if ( !root ) return {0, 0};
        
        auto p1 = path(root ->left);
        auto p2 = path(root ->right);
        
        pair<int, int> ans;
        
        ans.first = max( p1.first, max( p2.first, p1.second + p2.second ) );
        ans.second = max( p1.second, p2.second ) + 1;
        
        return ans;
    }
};