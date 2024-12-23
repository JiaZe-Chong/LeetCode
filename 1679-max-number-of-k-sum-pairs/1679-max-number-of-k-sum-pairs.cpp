class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        
        while (left < right) {
            int cur = nums[left] + nums[right];
            if (cur == k) {
                ans++;
                left++;
                right--;
            }
            else if (cur > k) {
                right--;
            }
            else {
                left++;
            }
        }
        
        return ans;    
    }
};