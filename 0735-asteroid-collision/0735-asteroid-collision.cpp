class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;
        vector<int> ans;
        
        for (int asteroid : asteroids) {
            if (asteroid > 0) dq.push_back(asteroid);
            else {
                while (dq.size() && -asteroid > dq.back()) dq.pop_back();
                if (dq.empty()) ans.push_back(asteroid);
                else if (dq.back() == -asteroid) dq.pop_back();
            }
        }
        
        while (dq.size()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        
        return ans;
    }
};