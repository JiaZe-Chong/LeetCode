class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, count = 0, ans = 0;
        
        while (right < nums.size()) {
            count += !nums[right++];
            
            if (count <= 1) {
                ans = max(ans, right - left - count);
            }
            else {
                count -= !nums[left++];
            }
        }
        
        return ans == nums.size() ? ans - 1 : ans;
    }
};