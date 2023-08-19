class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> m;
        
        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        
        vector< vector< string > > ans;
        
        auto iter = m.begin();
        
        while (iter != m.cend())
        {
            ans.push_back( (*iter).second );
            iter++;
        }
        
        return ans;
    }
};