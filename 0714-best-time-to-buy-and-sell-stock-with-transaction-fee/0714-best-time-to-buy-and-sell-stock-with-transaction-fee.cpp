class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int withoutStock = 0, withStock = INT_MIN;
        
        for (int price : prices) {
            int temp = withoutStock;
            withoutStock = max(withoutStock, withStock + price);
            withStock = max(withStock, temp - price - fee);
        }
        
        return withoutStock;
    }
};