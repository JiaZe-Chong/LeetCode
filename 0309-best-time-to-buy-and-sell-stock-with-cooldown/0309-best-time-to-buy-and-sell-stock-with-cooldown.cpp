class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int sold = 0;
        int rest = 0;
        int hold = INT_MIN;
        
        for ( int p : prices ) {
            
            int prevSold = sold;
            sold = hold + p;
            hold = max( hold, rest - p );
            rest = max( rest, prevSold );
        }
        
        return max( sold, rest );
        
    }
};