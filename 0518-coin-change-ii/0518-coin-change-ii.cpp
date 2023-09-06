class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return dfs( amount, coins, 0, 0 );
    }
    
    int dfs ( int amount, const vector<int>& coins, int i, int sum ) {
        
        if ( sum == amount ) return 1;
        
        if ( sum > amount ) return 0;
        
        if ( i == coins.size() ) return 0;
        
        if ( dp.find( {i, sum} ) != dp.end() ) return dp[ {i, sum} ];
        
        int ret =   dfs( amount, coins, i, sum + coins[i] ) +
                    dfs( amount, coins, i + 1, sum );
        
        dp[ {i, sum} ] = ret;
        
        return ret;
        
    }
    
    map< pair< int, int >, int > dp;
};