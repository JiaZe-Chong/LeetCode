class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0;
        vector<char> ret;
        
        char cur = chars[0];
        int num = 0;
        for(char c : chars) {
            if (c == cur) num++;
            else{
                ret.push_back(cur);
                if (num > 1) {
                    string n = to_string(num);
                    for (auto a : n) ret.push_back(a);   
                }
                cur = c;
                num = 1;
            }
        }
        ret.push_back(cur);
        if (num > 1) {
            string n = to_string(num);
            for (auto a : n) ret.push_back(a);   
        }
        
        chars = ret;
        return ret.size();
    }
};