class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++){
            cur += nums[i];
            if (cur < nums[i]){
                cur = nums[i];
            }
            if (cur > m) m = cur;
        }
        return m;
    }
};