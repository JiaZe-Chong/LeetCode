class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        vector<int> ans(n);
        
        memcpy(&(ans[0]), &(nums[n - k]), k * sizeof(int));   
        memcpy(&(ans[k]), &(nums[0]), (n - k) * sizeof(int));   
        
        nums = ans;
    }
};