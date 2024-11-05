class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        queue<int> q;
        
        visited.insert(0);
        q.push(0);
        
        while(q.size()) {
            int cur = q.front();
            q.pop();
            
            for (int room : rooms[cur]) {
                if (!visited.contains(room)) {
                    visited.insert(room);
                    q.push(room);
                }
            }
        }
        
        return visited.size() == rooms.size();
    }
};