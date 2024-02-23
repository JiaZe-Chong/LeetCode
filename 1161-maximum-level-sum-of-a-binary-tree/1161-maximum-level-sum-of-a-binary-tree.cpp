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
    int maxLevelSum(TreeNode* root) {
        
        int maxLevel = -1;
        queue<int> l;
        queue<TreeNode*> q;
        q.push(root);
        l.push(0);
        vector<int> sum;
        
        while(l.size()) {
            TreeNode* node = q.front();
            int level = l.front();
            q.pop();
            l.pop();
            
            if (level > maxLevel){
                maxLevel++;
                sum.push_back(0);
            }
            
            sum[level] += node->val;
            
            if (node->left) {
                q.push(node->left);
                l.push(level + 1);
            }
            
            if (node->right) {
                q.push(node->right);
                l.push(level + 1);
            }
        }
        
        vector<pair<int, int>> sumLevel;
        for (int i = 0; i < sum.size(); i++) {
            sumLevel.push_back({sum[i], i});
        }
        
        sort(sumLevel.begin(), sumLevel.end());
        int target = sumLevel[maxLevel].first;
        for (auto a : sumLevel)
            if (a.first == target)
                return a.second + 1;
        
        return sumLevel[maxLevel].second + 1;
    }
};