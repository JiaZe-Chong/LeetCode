class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        vector<int> cur;
        set<vector<int>> ret;
        dfs(0, cur, ret, nums);
        vector<vector<int>> ans;
        for (auto it : ret) ans.push_back( it );
        return ans;
    }
    
    void dfs( int start, vector<int>& cur, set<vector<int>>& ret, const vector<int>& nums ) {
        if ( ret.find( cur ) != ret.end() ) return;
        
        ret.insert( cur );
        for ( ; start < nums.size(); start++ ) {
            cur.push_back( nums[start] );
            dfs( start + 1, cur, ret, nums );
            cur.pop_back();
        }
        
    }
};