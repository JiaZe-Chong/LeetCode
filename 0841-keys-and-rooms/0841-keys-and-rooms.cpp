class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        queue<int> rooms_to_visit;
        
        rooms_to_visit.push(0);
        
        while(rooms_to_visit.size()) {
            
            int room = rooms_to_visit.front();
            rooms_to_visit.pop();
            
            if (!visited.contains(room)) {
                visited.insert(room);
                
                for (auto a : rooms[room]) {
                    if (!visited.contains(a)) {
                        rooms_to_visit.push(a);
                    }
                }
                        
            }
            
        }
        
        return visited.size() == rooms.size();
    }
};