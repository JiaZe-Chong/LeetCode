class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int withStock = INT_MIN, withoutStock = 0;
        
        for (int p : prices) {
            withoutStock = max(withoutStock, withStock + p);
            withStock = max(withStock, -p);
        }
        
        return withoutStock;
    }
};