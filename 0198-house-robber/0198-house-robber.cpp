class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, cur = 0, next = 0;
        
        for (int num : nums) {
            next = max(cur, prev + num);
            prev = cur;
            cur = next;
        }
        
        return cur;
    }
};