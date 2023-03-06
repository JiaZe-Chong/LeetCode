class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        vector<int> ans;
        for (auto a: nums){
            if (a == 0) n ++;
            else ans.push_back(a);
        }
        while(n--) ans.push_back(0);
        nums = ans;
    }
};