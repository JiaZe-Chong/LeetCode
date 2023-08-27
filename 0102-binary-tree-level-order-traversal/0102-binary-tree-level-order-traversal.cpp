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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if ( !root ) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push( root );
        
        while ( !( q.empty() ) ) {
            
            vector<int> vi;
            queue<TreeNode*> tempq;
            
            while ( !( q.empty() ) ) {
                
                vi.push_back( q.front()->val );
                if ( q.front()->left ) tempq.push( q.front()->left );
                if ( q.front()->right ) tempq.push( q.front()->right );
                q.pop();
                
            }
            
            ans.push_back(vi);
            q = tempq;
        }
        
        return ans;
    }
};