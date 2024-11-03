class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (int i : arr)
            m[i]++;
        
        unordered_set<int> s;
        
        for (const auto& [key, value] : m) {
            if (s.contains(value))
                return false;
            s.insert(value);
        }
        
        return true;
    }
};