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
                mx = max(mx, right - left);
            }
            else{
                while( m[s[right]] ) {
                    
                    m[s[left]] = false;
                    left++;
                    
                }
            }
            
        }
        
        mx = max(mx, right - left);
        
        return mx;
    }
};