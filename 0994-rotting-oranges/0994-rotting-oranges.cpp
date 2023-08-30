class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue< pair<int, int> > qp;
        map< pair<int, int>, bool > um;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( grid[i][j] == 1 ) um[{i, j}] = true;
                if ( grid[i][j] == 2 ) qp.push({i, j});
            }
        }
        
        while ( !qp.empty() ) {
            int num = qp.size();
            bool change = false;
            while( num-- ) {
                
                auto a = qp.front();
                qp.pop();
                
                for (int i = a.first - 1; i <= a.first + 1; i++) {
                    
                    if ( i < 0 || i >= m ) continue;
                    if ( grid[i][a.second] == 1 ) {
                        
                        change = true;
                        um[{i, a.second}] = false;
                        qp.push({i, a.second});
                        grid[i][a.second] = 2;
                        
                    }
                    
                }
                
                for (int i = a.second - 1; i <= a.second + 1; i++) {
                    
                    if ( i < 0 || i >= n ) continue;
                    if ( grid[a.first][i] == 1 ) {
                        
                        change = true;
                        um[{a.first, i}] = false;
                        qp.push({a.first, i});
                        grid[a.first][i] = 2;
                        
                    }
                    
                }
                
            }
            
            if ( change ) time++;
        }
        
        for (auto a : um) if ( a.second ) return -1;
        
        return time;
    }
};