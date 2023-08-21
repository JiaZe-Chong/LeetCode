class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0, right = 0;
        int mx = 0;
        unordered_map <char, bool> m;
        
        while( right < s.size() ) {
        
            if ( !m[s[right]] ){
                m[s[right]] = true;
                right++;
            }
            else{
                mx = max(mx, right - left);
                left++;
                right = left;
                m.clear();
            }
            
        }
        
        mx = max(mx, right - left);
        
        return mx;
    }
};