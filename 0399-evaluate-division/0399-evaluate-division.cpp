class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> eval;
        
        for (int i = 0; i < n; i++) {
            string top = equations[i][0];
            string bottom = equations[i][1];
            double value = values[i];
            
            eval[top].push_back({bottom, value});
            eval[bottom].push_back({top, 1 / value});
        }
        
        vector<double> ans;
        for (const auto& query : queries) {
            set<string> visited;
            ans.push_back(dfs(eval, query[0], query[1], visited));
        }
        return ans;
    }
    
    double dfs(unordered_map<string, vector<pair<string, double>>>& eval, string top, string bottom, set<string>& visited) {
        if (!eval.contains(top) || !eval.contains(bottom))
            return -1;
        
        if (top == bottom)
            return 1;
        
        for (const auto& [str, value] : eval[top]) {
            if (visited.contains(str))
                continue;
            visited.insert(str);
            double res = dfs(eval, str, bottom, visited);
            if (res != -1)
                return value * res;
        }
        
        return -1;
    }
};