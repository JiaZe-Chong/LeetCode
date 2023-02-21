class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while(l < h){
            int n = (h + l) / 2;
            if (n % 2 == 1) n--;
            
            if (nums[n] != nums[n + 1]) h = n;
            else l = n + 2;

        }
        return nums[l];
    }
};