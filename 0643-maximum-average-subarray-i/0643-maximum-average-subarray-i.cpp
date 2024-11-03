class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = 0, sum = 0;
        double ans = INT_MIN;
        
        while (right < nums.size()) {
            sum += nums[right++];
            
            if (right - left == k) {
                ans = max(ans, (double)sum / (right - left));
                sum -= nums[left++];
            }            
        }
        
        return ans;
    }
};