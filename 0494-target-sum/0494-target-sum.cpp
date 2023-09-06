class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs( target, nums, 0, 0 );
    }
    
    int dfs( const int& target, const vector<int>& nums, int i, int sum ) {
        
        if ( i == nums.size() ) return sum == target ? 1 : 0;
        
        if ( m.find({i, sum}) != m.end() ) return m[{i, sum}];
        
        int ret =   dfs( target, nums, i + 1, sum + nums[i] ) +
                    dfs( target, nums, i + 1, sum - nums[i] );
        
        m[{i, sum}] = ret;
        
        return ret;
        
    }
    
    map< pair<int, int>, int > m;
};