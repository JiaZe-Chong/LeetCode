class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        
        int i = entrance[0];
        int j = entrance[1];
        maze[i][j] = '+';
        dist[i][j] = 0;
        q.push({i, j});
        
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            
            if (maze[x][y] != '+' &&
               (x == 0 || x == maze.size() - 1 || y == 0 || y == maze[0].size() - 1))
                return dist[x][y];
            
            int curDist = dist[x][y];

            if ( x != 0 && maze[x - 1][y] != '+' && dist[x - 1][y] > curDist + 1) {
                dist[x - 1][y] = curDist + 1;
                q.push({x - 1, y});
            }
                
            if ( x != maze.size() - 1 && maze[x + 1][y] != '+' && dist[x + 1][y] > curDist + 1) {
                dist[x + 1][y] = curDist + 1;
                q.push({x + 1, y});
            }
            
            if ( y != 0 && maze[x][y - 1] != '+' && dist[x][y - 1] > curDist + 1) {
                dist[x][y - 1] = curDist + 1;
                q.push({x, y - 1});
            }
            
            if ( y != maze[0].size() - 1 && maze[x][y + 1] != '+' && dist[x][y + 1] > curDist + 1) {
                dist[x][y + 1] = curDist + 1;
                q.push({x, y + 1});
            }
        }
        
        return -1;
    }
};