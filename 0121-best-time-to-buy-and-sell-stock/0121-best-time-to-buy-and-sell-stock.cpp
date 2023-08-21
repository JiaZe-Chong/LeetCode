class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 0, right = 1;
        int dif = 0;
        
        while (right < prices.size()) {
            
            if ( prices[right] < prices[left] ){
                left = right;
            }
            else if ( dif < prices[right] - prices[left] ){
                dif = prices[right] - prices[left];
            }
            right++;
            
        }
        
        return dif;
    }
};