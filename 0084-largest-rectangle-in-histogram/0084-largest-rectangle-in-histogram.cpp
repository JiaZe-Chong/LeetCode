class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int, int>> sp;
        int ret = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            
            int start = i;
            
            while ( !sp.empty() && sp.top().second > heights[i] ) {
                
                int ind = sp.top().first;
                int width = i - ind;
                int height = sp.top().second;
                sp.pop();
                
                ret = max( ret, width * height );
                start = ind;
                
            }
            
            sp.push( {start, heights[i]} );
            
        }
        
        while ( !sp.empty() ) {
            int width = heights.size() - sp.top().first;
            int height = sp.top().second;
            sp.pop();
            
            ret = max( ret, width * height );
        }
        
        return ret;
        
    }
};