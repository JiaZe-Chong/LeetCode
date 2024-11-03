class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int len = 0;
        char cur = chars[0];
        
        for (const char& c : chars) {
            if (c == cur) {
                len++;
            }
            else {
                chars[ans++] = cur;
                if (len != 1) {
                    string num = to_string(len);
                    for (const char& n : num) {
                        chars[ans++] = n;
                    }   
                }
                cur = c;
                len = 1;
            }        
        }
        
        chars[ans++] = cur;
        if (len != 1) {
            string num = to_string(len);
            for (const char& n : num) {
                chars[ans++] = n;
            }   
        }
        
        return ans;
    }
};