class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int withoutStock = 0, withStock = INT_MIN;
        
        for (int price : prices) {
            
            int prevWithoutStock = withoutStock;
            withoutStock = max(withoutStock, withStock + price);
            withStock = max(withStock, withoutStock - price);
            
        }
        
        return withoutStock;
    }
};