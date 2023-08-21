class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int prev = INT_MAX;
        for (int i = 0; i < nums.size(); i++){

            if (prev == nums[i]) continue;
            else prev = nums[i];

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k){
                int n = nums[j] + nums[k] + nums[i];
                if (n == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int l = nums[j];
                    int h = nums[k];
                    while(j < k && l == nums[j]) j++;
                    while(j < k && h == nums[k]) k--;
                }
                else if (n > 0) k--;
                else if (n < 0) j++;
            }

        }

        return ans;
        
    }
};