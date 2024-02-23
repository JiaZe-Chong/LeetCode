/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool search(TreeNode* root, TreeNode* target, vector<TreeNode*>& vec) {
        if (!root) return false;
        
        vec.push_back(root);
        if (root == target) return true;
        if ( search(root->left, target, vec) || search(root->right, target, vec) )
            return true;
        vec.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp;
        vector<TreeNode*> vq;
        
        search(root, p, vp);
        search(root, q, vq);
        
        for (int i = vp.size() - 1; i >= 0; i--) {
            
            auto it = find(vq.begin(), vq.end(), vp[i]);
            if ( it != vq.end() )
                return vp[i];
            
        }
        
        return nullptr;
    }
};