class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        unordered_map<char, int> ms, mt;
        
        for (char c : t) mt[c]++;
        
        int left = 0, right = 0;
        
        string ans = "";
        bool first = false;
        
        ms[s[0]]++;
        while (right < s.size()) {
            bool hit = true;
            for ( auto it : mt ){
                if ( ms[it.first] < it.second ) hit = false;
            }
            
            int len = right - left + 1;
            if ( !hit ){         
                
                while ( ms[s[left]] > mt[s[left]] ){
                    ms[s[left]]--;
                    left++;
                }
                
                right++;
                ms[s[right]]++;
            }
            else if ( !first ){
                ans = s.substr( left, len  );        
                first = true;
                ms[s[left]]--;
                left++;
            }
            else if ( len < ans.size() ){
                ans = s.substr( left, len ); 
                ms[s[left]]--;
                left++;
            }
            else{
                ms[s[left]]--;
                left++;
            }
        }
        
        return ans;
    }
};