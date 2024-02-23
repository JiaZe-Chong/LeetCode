class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        
        int round = 0;
        
        for (; round < senate.length(); round++){
            if (senate[round] == 'R') rad.push(round);
            else if (senate[round] == 'D') dir.push(round);
        }
        
        while(rad.size() != 0 && dir.size() != 0) {
            
            int r = rad.front();
            int d = dir.front();
            
            rad.pop();
            dir.pop();
            
            if (d < r) dir.push(round);
            else rad.push(round);
            
            round++;
        }
        
        return rad.size() == 0 ? "Dire" : "Radiant"; 
    }
};