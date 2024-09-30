class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0, right = 0, sum = 0;
        
        while(right < nums.size()) {
            sum += nums[right];
            
            if (sum >= target)
                ans = min(ans, right - left + 1);
            
            while(left <= right && sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            
            right++;
        }
        
        
        
        
        return ans == INT_MAX ? 0 : ans;
    }
};