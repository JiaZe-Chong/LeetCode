class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cur = 0;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            
            if (!nums[right]) cur++;
            if (cur > k) {
                
                if (!nums[left]) cur--;
                left++;
                
            }
            
            if (cur <= k) ans = max(ans, right - left + 1);
            
        }
        
        return ans;
    }
};