class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector<int> cur;
        vector<vector<int>> ret;
        dfs( target, cur, 0, candidates, ret, 0 );
        return ret;
    }
    
    void dfs( int target, vector<int>& cur, int sum, const vector<int>& nums, vector<vector<int>>& ret, int start ) {
        
        if ( sum == target ) {
            ret.push_back( cur );
        }
        
        if ( sum >= target ) return;
        
        for (int i = start; i < nums.size(); i++) {
            if ( i > start && nums[i] == nums[i - 1] ) continue;
            cur.push_back( nums[i] );
            dfs( target, cur, sum + nums[i], nums, ret, i + 1 );
            cur.pop_back();
        }
        
    }
};