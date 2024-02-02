class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        double cur = 0.0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (i >= k) {
                ans = max(ans, cur);
                cur -= (double)nums[i - k] / k;
            }
            
            cur += (double)nums[i] / k;            
        }
        
        ans = max(ans, cur);
        
        return ans;
    }
};