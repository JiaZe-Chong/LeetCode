class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        bool can[n];
        for (auto & a : can) a = false;

        can[n - 1] = true;
        for (int i = n - 2; i >= 0; i--){
            for (int j = 1; j <= nums[i] && i + j < n; j++){
                if (can[i + j]){
                    can[i] = true;
                    break;
                } 
            }
        }

        return can[0];
    }
};