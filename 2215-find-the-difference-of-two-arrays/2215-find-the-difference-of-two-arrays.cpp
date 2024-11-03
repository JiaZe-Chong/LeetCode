class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;
        for (int i : nums1) set1.insert(i);
        for (int i : nums2) set2.insert(i);
        
        for (int i : nums1) {
            if (set2.contains(i)) {
                set1.erase(i);
                set2.erase(i);
            }
        }
        
        return {vector<int>(set1.begin(), set1.end()), vector<int>(set2.begin(), set2.end())};     
    }
};