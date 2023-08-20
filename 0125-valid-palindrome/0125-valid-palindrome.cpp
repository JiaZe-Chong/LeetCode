class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, tail = s.length() - 1;
        
        while (head < tail) {   
            
            while( head <= s.length() - 1 && !isalpha(s[head]) && !isdigit(s[head]) ) head++;
            while( tail >= 0 && !isalpha(s[tail]) && !isdigit(s[tail]) ) tail--;
            
            if (head > tail) return true;
            
            if ( tolower( s[head] ) != tolower( s[tail] ) ) return false;
            head++;
            tail--;
        }
        return true;
    }
};