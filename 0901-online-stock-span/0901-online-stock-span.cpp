class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        while( stk.size() && stk.top().first <= price ) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
        
    }
    
    stack<pair<int, int>> stk;
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */