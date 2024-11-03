class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, ans = 0;
        
        while(right < nums.size()) {
            count += !nums[right++];
            
            if (count <= k) {
                ans = max(ans, right - left);
            }
            else {
                count -= !nums[left++];
            }
        }
        
        return ans;
    }
};