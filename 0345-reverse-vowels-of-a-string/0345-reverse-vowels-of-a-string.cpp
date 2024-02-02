class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        
        int left = 0;
        int right = s.length() - 1;
        
        while(left < right) {
            
            while (left != s.length() && !isVowel(s[left])) 
                left++;
            while (right != 0 && !isVowel(s[right]))
                right--;
                   
            if (right <= left) break;
                   
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
                   
        }
        
        return s;
        
    }
};