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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()) {
            int num = q.size();
            int last = 0;    
            while (num--) {
                TreeNode* node = q.front();
                last = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            ans.push_back(last);
        }
        return ans;        
    }
};