class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int space[n][m];
        for (auto &i : space) for (auto &j : i) j = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (obstacleGrid[i][j] == 1) continue;
                if (i == 0 && j == 0) space[0][0] = 1;
                if (i > 0) space[i][j] += space[i - 1][j];
                if (j > 0) space[i][j] += space[i][j - 1];
            }
        }
        return space[n - 1][m - 1];
    }
};