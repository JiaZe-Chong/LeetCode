class Solution {
public:
    int temp(char c) {
        
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        
        return -1;
    }
    
    int romanToInt(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {            
            if (s[i] == 'I') {
                if (i < s.length() - 1) {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                        ans += temp(s[i + 1]) - 1;
                        i++;
                        continue;
                    }
                }
            }
            
            if (s[i] == 'X') {
                if (i < s.length() - 1) {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                        ans += temp(s[i + 1]) - 10;
                        i++;
                        continue;
                    }
                }
            }
            
            if (s[i] == 'C') {
                if (i < s.length() - 1) {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                        ans += temp(s[i + 1]) - 100;
                        i++;
                        continue;
                    }
                }
            }
            
            ans += temp(s[i]);
        }
        
        return ans;
    }
};