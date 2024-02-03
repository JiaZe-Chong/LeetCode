class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (int i : arr) m[i]++;
        
        set<int> s;
        
        for (auto it : m) {
            int i = it.second;
            if (s.find(i) == s.end()) s.insert(i);
            else return false;
        }
        
        return true;
    }
};