class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int ans = nums[0];
        
        for (int num : nums) {
            cur += num;
            ans = max(ans, cur);
            if (cur < 0) 
                cur = 0;
        }
        
        return ans;
    }
};