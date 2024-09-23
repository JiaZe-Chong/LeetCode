class Solution {
public:
    
    vector<string> split(string s) {
        stringstream ss(s);
        istream_iterator<std::string> begin(ss);
        istream_iterator<std::string> end;
        vector<std::string> vstrings(begin, end);
        return vstrings;
    }
    
    bool wordPattern(string pattern, string s) {
        auto vec = split(s);
        
        if (pattern.size() != vec.size())
            return false;
        
        unordered_map<string, char> m1;
        unordered_map<char, string> m2;
        
        for (int i = 0; i < pattern.size(); i++) {
            
            if (!m1.contains(vec[i]) && !m2.contains(pattern[i])) {
                m1[vec[i]] = pattern[i];
                m2[pattern[i]] = vec[i];
            }
            else if (m1.contains(vec[i]) != m2.contains(pattern[i])) {
                return false;
            }
            else {
                if (m1[vec[i]] != pattern[i] || m2[pattern[i]] != vec[i])
                    return false;
            }
            
        }
        
        return true;
    }
};