class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size()) return false;
        
        unordered_map<char, int> m;
        
        for (char c : s1) m[c]++;
        
        int n = s1.size();
        
        int left = 0, right = left + n - 1;
        
        unordered_map<char, int> cache;
        
        for (int i = left; i <= right; i++) cache[s2[i]]++;
        
        while (right < s2.size()) {
         
            bool hit = true;
            for (auto it : m) {
                char c = it.first;
                int count = it.second;
                if ( m[c] > cache[c] ) hit = false;
            }
            if (hit) return true;
            
            cache[s2[left]]--;
            left++;
            right++;
            cache[s2[right]]++;
        }
        
        return false;
    }
};