class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        
        for (int i : nums1) set1.insert(i);
        for (int i : nums2) set2.insert(i);
        
        vector<vector<int>> ans(2, vector<int>());
        
        for (int i : set1) if (set2.find(i) == set2.end()) ans[0].push_back(i);
        for (int i : set2) if (set1.find(i) == set1.end()) ans[1].push_back(i);
        
        return ans;
    }
};