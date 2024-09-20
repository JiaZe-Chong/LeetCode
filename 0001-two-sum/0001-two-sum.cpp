class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vpii;
        
        for (int i = 0; i < nums.size(); i++) {
            vpii.push_back({nums[i], i});
        }
        
        sort(vpii.begin(), vpii.end());
        
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            
            int sum = vpii[left].first + vpii[right].first;
            
            if (sum == target)
                return {vpii[left].second, vpii[right].second};
            
            else if (sum > target)
                right--;
            
            else if (sum < target)
                left++;
            
        }
        
        return {-1, -1};
    }
};