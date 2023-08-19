class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector< pair< int, int > > vp;
        
        for (int i = 0; i < nums.size(); i++)
            vp.push_back( {nums[i], i} );
        
        
        sort( vp.begin(), vp.end() );
        
        int head = 0, tail = vp.size() - 1;
        
        while( head < tail )
        {
            int s = vp[head].first + vp[tail].first;
            
            if ( s == target ) return { vp[head].second, vp[tail].second };
            
            if ( s > target ) tail--;
            else head++;
            
        }
        
        return {-1, -1};
    }
};