class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < nums.size(); i++) vp.push_back({nums[i], i});
        sort(vp.begin(), vp.end());
        for (int i = 1; i < vp.size(); i++){
            if (vp[i].first == vp[i - 1].first && abs(vp[i - 1].second - vp[i].second) <= k){
                cout << abs(vp[i - 1].second - vp[i].second) << endl;
                cout << vp[i].first << endl << vp[i - 1].first << endl << vp[i].second << endl << vp[i - 1].second << endl;
                return true;
            }      
        }
        return false;
    }
};