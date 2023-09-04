class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int n : nums) target += n;
        if ( target % 2 ) return false;
        target /= 2;
        
        unordered_set<int> dp;
        dp.insert( 0 );
        
        for (int n : nums) {
            unordered_set<int> nextIte;
            for (auto it : dp) {
                if ( it + n == target ) return true;
                nextIte.insert( it );
                nextIte.insert( it + n );
            }
            dp = nextIte;
        }
        return false;
    }
};