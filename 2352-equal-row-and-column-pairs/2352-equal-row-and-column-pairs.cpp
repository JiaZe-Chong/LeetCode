class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int n = grid.size();
        int ans = 0;
        
        for (auto a : grid) m[a]++;
        
        for (int j = 0; j < n; j++) {
            vector<int> temp;
            for (int i = 0; i < n; i++)
                temp.push_back(grid[i][j]);
            
            ans += m[temp];
        }
            
        return ans;
        
    }
};