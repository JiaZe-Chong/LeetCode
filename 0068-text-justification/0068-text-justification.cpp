class Solution {
public:
    string merge(const vector<string>& words, int len, int maxWidth, bool last) {
        string ans = "";   
        int spaces = words.size() - 1;
        
        if (spaces == 0) {
            ans += words[0];
            for (int i = 0; i < maxWidth - len; i++)
                ans += ' ';
        }
        else if (!last) {
            int spaceLen = (maxWidth - len) / spaces;
            int padding = (maxWidth - len) % spaces;
            
            for (int i = 0; i < spaces + 1; i++) {
                ans += words[i];
                
                if (i != spaces)
                    for (int j = 0; j < spaceLen; j++)
                        ans += ' ';
                
                if (padding) {
                    ans += ' ';
                    padding--;
                }
                        
            }   
        }
        else {
            for (string word : words) {
                ans += word;
                if (ans.length() < maxWidth)
                    ans += ' ';
            }
            for (; ans.length() < maxWidth; ans += ' ');
        }
        
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        
        vector<string> cur;
        int curLen = 0;
        
        for (string word : words) {
            if (curLen + cur.size() + word.length() > maxWidth) {
                ans.push_back(merge(cur, curLen, maxWidth, false));
                cur.clear();
                curLen = 0;
            }
            
            cur.push_back(word);
            curLen += word.length();
        }
        
        if (curLen)
            ans.push_back(merge(cur, curLen, maxWidth, true));
        
        return ans;
    }
};