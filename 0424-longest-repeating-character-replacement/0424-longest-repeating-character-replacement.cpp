class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, vector<int>> m;
        int n = s.size();
        
        for (int i = 0; i < n; i++) m[s[i]].push_back(i);
        
        int mx = 0;
        
        for (auto it : m) {
            
            int left = 0, right = 0;
            
            while ( right < it.second.size() ) {
                
                while ( it.second[right] - it.second[left] - ( right - left ) > k ) left++;
                
                int ext = k - ( it.second[right] - it.second[left] - ( right - left ) );
                int cur = it.second[right] - it.second[left] + 1;
                
                if ( it.second[left] > 0 ){
                    cur += min( it.second[left], ext );
                    ext -= min( it.second[left], ext );
                }
                
                if ( it.second[right] < n ){
                    cur += min( n - it.second[right] - 1, ext );
                }
                
                mx = max(mx, cur);
                right++;
            }
            
            
        }
        
        return mx;
        
    }
};