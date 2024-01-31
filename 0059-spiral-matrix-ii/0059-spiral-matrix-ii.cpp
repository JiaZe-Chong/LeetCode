class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int l = 0, r = n - 1, t = 0, b = n - 1;
        int count = 1;
        while ( l <= r && t <= b ) {
            
            for (int i = l ; i <= r; i++) {
                ans[t][i] = count;
                count++;
            }
            t++;
            
            for (int i = t; i <= b; i++) {
                ans[i][r] = count;
                count++;
            }
            r--;
            
            if ( t <= b ) {
                for (int i = r; i >= l; i--) {
                    ans[b][i] = count;
                    count++;
                }
            }
            b--;
            
            if ( l <= r ) {
                for (int i = b; i >= t; i--) {
                    ans[i][l] = count;
                    count++;
                }
            }
            l++;
            
        }
        
        return ans;
    }
};