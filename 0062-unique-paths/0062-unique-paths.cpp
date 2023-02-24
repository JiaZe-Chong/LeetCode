class Solution {
public:
    int uniquePaths(int m, int n) {
        int space[m][n];
        space[0][0] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0) continue;
                space[i][j] = 0;
                if (i > 0) space[i][j] += space[i - 1][j];
                if (j > 0) space[i][j] += space[i][j - 1];
            }
        }
        
        return space[m - 1][n - 1];
    }
    
    
};