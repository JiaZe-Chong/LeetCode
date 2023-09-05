class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if ( n == 1 ) return nums[0];
        
        int r1 = robber( 0, n - 2, nums );
        int r2 = robber( 1, n - 1, nums );
        
        return max( r1, r2 );
        
    }
    
    int robber( int start, int end, const vector<int>& nums ) {
        
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = start; i <= end; i++) {
            
            next = max( curr, prev + nums[i] );
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};