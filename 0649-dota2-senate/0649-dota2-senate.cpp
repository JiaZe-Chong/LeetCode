class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int i = 0;
        for (; i < senate.length(); i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        
        while(radiant.size() && dire.size()) {
            int r = radiant.front();
            int d = dire.front();
            dire.pop();
            radiant.pop();
            
            if (r < d) {
                radiant.push(i++);   
            }
            else {
                dire.push(i++);
            }
        }
        
        return radiant.size() ? "Radiant" : "Dire";
    }
};