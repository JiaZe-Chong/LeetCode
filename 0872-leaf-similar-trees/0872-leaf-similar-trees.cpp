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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return val(root1) == val(root2);
    }
    
private:
    vector<int> val(TreeNode* node) {
        
        vector<int> ans;
        
        if ( !node->left && !node->right ) return {node->val};
        
        if ( node->left )
            for (int i : val(node->left))
                ans.push_back(i);
        
        if ( node->right )
            for (int i : val(node->right))
                ans.push_back(i);
        
        return ans;
    }
};