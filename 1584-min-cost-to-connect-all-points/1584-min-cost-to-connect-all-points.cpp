class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int MST = 0;
        vector<int> minDist( n, INT_MAX );
        vector<bool> inMST( n, false );
        
        minDist[0] = 0;
        int ret = 0;
        
        while ( MST < n ) {
            int curMin = INT_MAX;
            int curNode = -1;
            
            for (int i = 0; i < n; i++) {
                if ( !inMST[i] && minDist[i] < curMin ) {
                    curMin = minDist[i];
                    curNode = i;
                }
            }
            
            inMST[curNode] = true;
            minDist[curNode] = curMin;
            ret += curMin;
            MST++;
            
            for (int i = 0; i < n; i++) {
                if ( !inMST[i] ) {
                    int dist = abs( points[i][0] - points[curNode][0] ) + abs( points[i][1] - points[curNode][1] );
                    if ( dist < minDist[i] ) 
                        minDist[i] = dist;
                }      
            }
        }
        
        return ret;
        
    }
};