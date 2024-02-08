class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        
        for (int spell : spells) {
            int pos = lower_bound(potions.begin(), potions.end(), ceil((double)success / spell)) - potions.begin();
            ans.push_back(potions.size() - pos);
        }
        
        return ans;
    }
};