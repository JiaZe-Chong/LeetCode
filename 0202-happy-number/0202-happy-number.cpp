class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext( n );
        
        while ( slow != fast ) {
            
            slow = getNext( slow );
            fast = getNext( getNext( fast ) );
            
        }
        
        return fast == 1;
        
    }
    
    int getNext( int n ) {
        int ret = 0;
        while ( n > 0 ) {
            
            ret += pow( (n % 10), 2 );
            n /= 10;
    
        }
        return ret;
    }
};