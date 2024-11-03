class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int threshold = -1;
        for (const auto& candy : candies) {
            threshold = max(threshold, candy);
        }
        
        vector<bool> ans;
        for (const auto& candy : candies) {
            ans.push_back(candy + extraCandies >= threshold);
        }
        
        return ans;
    }
};