class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        
        int tempMax = -1;
        for (int i : candies)
            tempMax = max(i, tempMax);
        
        for (int i = 0; i < candies.size(); i++)
            ans[i] = candies[i] + extraCandies >= tempMax;
        
        return ans;
    }
};