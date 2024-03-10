class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int n = s.length();
        unordered_map<char, char> umap;
        set<char> mapped;
        
        for (int i = 0; i < n; i++) {
            if (!umap[s[i]]) {
                if (mapped.contains(t[i]))
                    return false;
                
                mapped.insert(t[i]);
                umap[s[i]] = t[i];
            }
            else {
                if (umap[s[i]] != t[i])
                    return false;
            }
            
        }
        
        return true;
    }
};