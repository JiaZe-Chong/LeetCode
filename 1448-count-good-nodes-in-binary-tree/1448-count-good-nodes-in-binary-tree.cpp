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
        vector<int> path;
        return utility(root, path);
    }
    
    int utility(TreeNode* root, vector<int>& path) {
        if (!root)
            return 0;
        
        int ans = 0;
        
        bool good = true;
        for (int i : path)
            if (i > root->val)
                good = false;
        if (good)
            ans++;
        
        path.push_back(root->val);
        ans += utility(root->left, path);
        ans += utility(root->right, path);
        path.pop_back();
        
        return ans;
    }
};