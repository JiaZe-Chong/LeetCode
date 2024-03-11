class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        
        for (int num : nums) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + num);
            prev2 = temp;
        }
        
        return prev1;
    }
};