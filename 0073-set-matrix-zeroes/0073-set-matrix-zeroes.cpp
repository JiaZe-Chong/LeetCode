class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {        
        stack<pair<int, int>> S;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0) S.push({i, j});
            }
        }
        
        while(S.size() != 0){
            pair<int, int> pr = S.top();
            S.pop();
            for (int i = 0; i < matrix.size(); i++){
                matrix[i][pr.second] = 0;
            }
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[pr.first][j] = 0;
        }
    }
};