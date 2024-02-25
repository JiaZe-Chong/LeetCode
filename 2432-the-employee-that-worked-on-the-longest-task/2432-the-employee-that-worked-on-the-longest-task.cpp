class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int curMax = 0;
        int curId;
        int prevCheckout = 0;
        
        for (auto log : logs) {
            if (log[1] - prevCheckout > curMax) {
                curId = log[0];
                curMax = log[1] - prevCheckout;
            }
            else if (log[1] - prevCheckout == curMax) {
                curId = min(curId, log[0]);
            }
    
            prevCheckout = log[1];
        }
        
        return curId;
    }
};