class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> eval;
        
        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            eval[a].push_back( {b, val} );
            eval[b].push_back( {a, 1 / val} );
        }
        
        for (auto query : queries) {
            unordered_set<string> visited;
            double res = dfs( eval, query[0], query[1], visited );
            ans.push_back( res );
        }
        
        return ans;
    }
    
    double dfs(unordered_map<string, vector<pair<string, double>>>& eval, string src, string des, unordered_set<string>& visited) {
        if (!eval.contains(src)) return -1;
        if (src == des) return 1;
        
        for (auto node : eval[src]) {
            if (visited.contains(node.first)) continue;
            visited.insert(node.first);
            double res = dfs(eval, node.first, des, visited);
            if (res != -1) return res * node.second;
        }
        
        return -1;
    }
};