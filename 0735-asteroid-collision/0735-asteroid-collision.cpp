class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        deque<int> pos;
        
        for (int i : asteroids) {
            
            if ( i < 0 && pos.empty() ) ans.push_back(i);
            else if ( i < 0 ) {
                
                while ( pos.size() && pos.back() < abs(i) ) pos.pop_back();
                
                
                if ( pos.empty() ) ans.push_back(i);
                else if ( pos.back() == abs(i) ) pos.pop_back();
                
            }
            else pos.push_back(i);
            
            
        }
        
        while(pos.size()) {
            ans.push_back(pos.front());
            pos.pop_front();
        }
        
        return ans;
    }
};