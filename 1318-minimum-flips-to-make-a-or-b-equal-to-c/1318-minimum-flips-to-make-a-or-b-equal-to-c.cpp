class Solution {
public:
    int minFlips(int a, int b, int c) {
        int num = 0;
        
        while ( c != 0 ) {
            int target = c & 1;
            int cur = (a | b) & 1;
            
            if (cur != target){
                num++;
                num += (a & b) & 1;
            }

            c >>= 1;
            a >>= 1;
            b >>= 1;
        }
        
        while ( a != 0 ) {
            if ( a & 1 )
                num++;
            a >>= 1;
        }
        
        while ( b != 0 ) {
            if ( b & 1 )
                num++;
            b >>= 1;
        }
        
        
        return num;
    }
};