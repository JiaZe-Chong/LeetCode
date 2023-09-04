class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int curMin = 1;
        int curMax = 1;
        
        for (int n : nums) {
            
            int temp = curMax * n;
            curMax = max( max( curMax * n, curMin * n ), n );
            curMin = min( min( temp, curMin * n ), n );
            ret = max( ret, curMax );
            
        }
        
        return ret;
    }
};