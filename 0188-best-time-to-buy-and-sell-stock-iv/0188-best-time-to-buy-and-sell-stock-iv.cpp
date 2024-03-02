class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> withStock(k, INT_MIN);
        vector<int> withoutStock(k, 0);
        
        for (int price : prices) {
            
            for (int i = 0; i < k; i++) {
                
                if (i == 0) {
                    withStock[i] = max(withStock[i], -price);    
                }
                else {
                    withStock[i] = max(withStock[i], withoutStock[i-1] - price);
                }
                
                withoutStock[i] = max(withoutStock[i], withStock[i] + price);
                
            }
            
        }
        
        return withoutStock[k - 1];
    }
};