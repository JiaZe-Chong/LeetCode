class Solution {
public:
    int reverse(int x) {
        
        long a = 0;
        
        while(x != 0){
            a = (a * 10) + (x % 10);
            x = x / 10;
        }
        
        if (a >= INT_MAX || a <= -1 * INT_MAX) return 0;
        
        return a;
        
    }
};