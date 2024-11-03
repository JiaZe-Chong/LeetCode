class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first, second;
        first = second = INT_MAX;
        
        for (const auto& i : nums) {
            if (i <= first) first = i;
            else if (i <= second) second = i;
            else return true;
        }
        
        return false;
    }
};