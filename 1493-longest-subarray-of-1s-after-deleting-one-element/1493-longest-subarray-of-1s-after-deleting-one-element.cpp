class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur = 0;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            
            if (!nums[right]) cur++;
            if (cur > 1) {
                
                if (!nums[left]) cur--;
                left++;
                
            }
            
            if (cur <= 1) ans = max(ans, right - left);
            
        }
        
        return ans;
    }
};