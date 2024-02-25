class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        
        while(i < name.size() && j < typed.size()) {    
            if (name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (i != 0 && name[i - 1] == typed[j]) {
                j++;
            }
            else 
                return false;
        }
        
        while (typed[j] == name[i - 1]) j++;
        
        return j == typed.size() && i == name.size();
    }
};