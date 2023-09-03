class Solution {
public:
    double myPow(double x, int n) {
        
        long exp = abs( n );
        double ret = 1.0;
        double cur = x;
        
        for ( long i = exp; i > 0; i /= 2 ) {
            if ( i % 2 )
                ret *= cur;
            cur *= cur;
        }
        
        if ( n < 0 ) return 1 / ret;
        return ret;
    }
};