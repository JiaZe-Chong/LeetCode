class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int withStock1 = INT_MIN, withoutStock1 = 0;
        int withStock2 = INT_MIN, withoutStock2 = 0;
        
        for (int price : prices) {
            
            withStock1 = max(withStock1, -price);
            withoutStock1 = max(withoutStock1, withStock1 + price);
            withStock2 = max(withStock2, withoutStock1 - price);
            withoutStock2 = max(withoutStock2, withStock2 + price);
            
        }
        
        return withoutStock2;
    }
};