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
        return toVec(root1) == toVec(root2);
    }
    
    vector<int> toVec(TreeNode* root) {
        if (!root->left && !root->right)
            return {root->val};
        
        vector<int> ans;
        if (root->left) 
            for (int i : toVec(root->left))
                ans.push_back(i);
        
        if (root->right)
            for (int i : toVec(root->right))
                ans.push_back(i);
        
        return ans;
    }
};