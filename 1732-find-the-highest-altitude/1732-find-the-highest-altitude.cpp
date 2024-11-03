class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0;
        int ans = 0;
        
        for (const auto& i : gain) {
            cur += i;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};